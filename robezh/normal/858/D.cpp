#include<cstdio> 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int ind(char c){
	return c - '0';
}

bool cmp(string a, string b) {
    return a.size() < b.size();
}

vector<string> gen(string str) {
    vector<string> res;
    set<string> S;
    
    //printf("Start inserting\n");
    
    for(int i = 0; i < str.length(); i++){
    	string a = "";
    	for(int j = i; j < str.length(); j++){
    		a += str[j];
    		S.insert(a);
		}
	}
	
	//printf("Inserted to sets\n");
	for(set<string>::iterator it = S.begin(); it != S.end(); it ++){
		res.push_back(*it);
	}
	//printf("Inserted to vector\n");
    sort(res.begin(), res.end(), cmp);
    
    return res;
}

vector<string> subs[70005];
//int sublen[70005];
const int MAX = 2500000;
const int C = 10;

int trie[MAX][C];
int triesize = 0;
int en[MAX];

int insert(string s){
	int node = 0;
	for(int i = 0; i < s.length(); i++){
		//printf("%d out ",i);
		if(trie[node][ind(s[i])]){
			node = trie[node][ind(s[i])];
		}
		else{
			//printf("%d in ",i);
			triesize ++;
			trie[node][ind(s[i])] = triesize;
			node = triesize;
		}
	}
	en[node]++;
}

int get(string s){
	int node = 0;
	for(int i = 0; i < s.length(); i++){
		if(trie[node][ind(s[i])]){
			node = trie[node][ind(s[i])];
		}
		else{
			return -1;
		}
	}
	return en[node];
}

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	string tmp;
	for(int i = 0; i < n; i++){
		getline(cin,tmp);
		string a = tmp;
		subs[i] = gen(tmp);
		for(int j = 0; j < subs[i].size(); j++){
			insert(subs[i][j]);
			//cout<<subs[i][j]<<endl;
		}
//		while(!a.empty()){
//			insert(a);
//			//cout<<"a == "<<a<<endl;
//			a.erase(0,1);
//		}
	}
	//cout<<"get000 = "<<get("000")<<endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < subs[i].size(); j++){
			if(get(subs[i][j]) == 1){
				cout<<subs[i][j]<<endl;
				break;
			}
		}
	}
	
	return 0;
}