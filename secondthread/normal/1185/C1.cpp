#include <bits/stdc++.h>

using namespace std;
const int blockSize=100;
const int rebuildTime=0;
typedef long long ll;

struct Block {
	ll sum;
	vector<int> items;

	Block():sum(0) {
	}
	
	void add(int n) {
		sum+=n;
		for (int i=0; i<=items.size(); i++) {
			if (i==items.size()) {
				items.push_back(n);
				break;
			}
			else {
				if (items[i]>=n) {
					items.insert(items.begin()+i, n);
					break;
				}
			}
		}
	}
	
};

vector<Block> rebuild(vector<Block> orig) {
	vector<int> items;
	for (Block &b:orig)
		for (int &i:b.items) items.push_back(i);
	vector<Block> toReturn;
	for (int i=0; i<items.size(); i++) {
		if (i%blockSize==0)
			toReturn.push_back(Block());
		toReturn[toReturn.size()-1].add(items[i]);
	}

	if (toReturn.size()==0)
		toReturn.push_back(Block());
	return toReturn;
}

int countMaxKeep(vector<Block> blocks, int maxSum) {
	int toReturn=0, blockNum=0;
	while (blockNum<blocks.size()&&blocks[blockNum].sum<=maxSum) {
		maxSum-=blocks[blockNum].sum;
		toReturn+=blocks[blockNum].items.size();	
		blockNum++;
	}
	if (blockNum<blocks.size()) {
		for (int i=0; i<blocks[blockNum].items.size(); i++) {
			if (blocks[blockNum].items[i]<=maxSum) {
				maxSum-=blocks[blockNum].items[i];
				toReturn++;
			}
		}
	}

	return toReturn;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, totalTime; cin>>n>>totalTime;
	vector<Block> blocks;
	blocks.push_back(Block());
	for (int person=0; person<n; person++) {
		//cout<<"Processing person "<<person<<endl;
		if (person%blockSize==0) {
			blocks=rebuild(blocks);
		}
		//cout<<"rebuilt"<<endl;
		int time; cin>>time;
		int maxSum=totalTime-time;
		int canKeep=countMaxKeep(blocks, maxSum);
		//cout<<"max keep: "<<canKeep<<endl;
		int leave=person-canKeep;
		cout<<leave<<' ';
		for (int block=0; block<=blocks.size(); block++) {
			//cout<<"Trying to add to block "<<block<<blocks.size()<<endl;
			if (block==blocks.size()) {
				blocks[blocks.size()-1].add(time);
			}
			else {
				//cout<<blocks[block].items.size()<<" <- "<<endl;
				if (blocks[block].items.empty()||
						blocks[block].items[blocks[block].items.size()-1]>=time) {
					blocks[block].add(time);
					//cout<<"Added person to block: "<<block<<endl;
					break;
				}
			}
		}
		//cout<<"Added"<<endl;
	}

	cout<<endl;
	return 0;
}