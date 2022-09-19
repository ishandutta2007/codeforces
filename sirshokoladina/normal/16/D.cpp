#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int a[200];

int main(){
	int n;
	scanf("%d\n",&n);
	forn(i,n){
		string s;
		getline(cin,s);
		a[i]=(s[7]=='p');
		a[i]=12*a[i]+(s[1]-'0')*10+(s[2]-'0');
		if(a[i]==12 || a[i]==24)
			a[i]-=12;
		a[i]=60*a[i]+(s[4]-'0')*10+(s[5]-'0');
	}
	int k=1;
	int ans=1;
	for(int i=1;i<n;i++)
		if(a[i]==a[i-1]){
			k++;
			if(k==11){
				k=1;
				ans++;
			}
		}else{
			k=1;
			if(a[i]<a[i-1])
				ans++;
		}
	cout<<ans;
	return 0;
}