#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> dltd[30];
vector<int> tobedlt[30];
int bit[280000];
int n;
int len = 1;



int sum(int i){
	int s = 0;
	while(i > 0){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x){
	while(i <= 2 * len){
		bit[i] += x;
		i += i & (-i);
	}
}

int reset_bit(int len1){
	len = len1;
	fill(bit, bit+270000, 0);
	for(int i = 1; i <= len; i++){
		add(i, 1);
	}
	
}

int bi_search(int k, int len){
	int left = 1;
	int right = len;
	if(sum(left) == k) return left;
	while(left + 1 < right){
		int mid = (left+right) / 2;
		if(sum(mid) >= k) right = mid;
		else left = mid;
	}
	return right;
}

int main(){
	int cnt[30];
	string str;
	int n, m;
	int a; char c;
	cin >> n;
	getchar();
	getline(cin, str);
	fill(cnt, cnt+26, 0);
	for(int i = 0; i < str.length(); i++){
		cnt[str[i]-'a'] ++;
	}
	for(int i = 0; i <= 'z' - 'a'; i++) cnt[i] *= n;
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> c;
		tobedlt[c-'a'].push_back(a);
	}
	for(int i = 0; i <= 'z' - 'a'; i++){
		//cout << "re";
		//cout << cnt[0];
		reset_bit(cnt[i]);
		//cout << "i = " << i << " cnt[i] = " << cnt[i] << endl;
		for(int j = 0; j < tobedlt[i].size(); j++){
			//cout << "1";
			int del = bi_search(tobedlt[i][j], cnt[i]);
			//cout << "del = " << del << endl;
			//cout << "2";
			add(del, -1);
			//cout << "3";
			dltd[i].push_back(del);
		}
		sort(dltd[i].begin(), dltd[i].end());
//		cout << (char)('a' + i) << " ";
//		for(int j = 0; j < dltd[i].size(); j++){
//			cout << dltd[i][j] << " ";
//		}
//		cout << endl;
	}
	int cntr[30];
	int inddel[30];
	fill(cntr, cntr+30, 0);
	fill(inddel, inddel+30, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < str.length(); j++){
			int c = str[j]-'a';
			cntr[c] ++;
			int index = inddel[str[j]-'a'];
			if(index < dltd[c].size() && cntr[c] == dltd[c][index]){
				inddel[str[j]-'a'] ++;
			}
			else cout << str[j];
		}
	}
	
}