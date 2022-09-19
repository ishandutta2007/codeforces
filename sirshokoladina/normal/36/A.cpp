#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	int n;
	string s;
	cin>>n>>s;
	int k=0;
	int l=0;
	int p=0;
	forn(i,n)
		if(s[i]=='1'){
			if(k>1)
				if(i-p != l){
					cout<<"NO";
					return 0;
				}
			if(k>0)
				l=i-p;
			k++;
			p=i;
		}
	cout<<"YES";
	return 0;
}