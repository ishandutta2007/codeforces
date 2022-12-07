#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>

using namespace std;
int n,a,b;
string s;

int main(void){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin >> n >> a >> b;
	cin >> s;
	int k=s.size()/n;
	int o=s.size()%n;
	int x=0;
	if (k<a||k+(o>0)>b){
		puts("No solution");
		return 0;
	}
	for (int i=0;i<n-o;i++){
		for (int j=0;j<k;j++)cout << s[x++];
		puts("");
	}
	for (int i=0;i<o;i++){
		for (int j=0;j<k+1;j++)cout << s[x++];
		puts("");
	}
	return 0;
}