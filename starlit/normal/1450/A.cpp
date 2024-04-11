#include<bits/stdc++.h>
const int N=2003;
using namespace std;
int n,m;
char s[N];
int main(){
	scanf("%d",&n);
	for(;n--;){
		scanf("%d%s",&m,s);
		sort(s,s+m);
		puts(s);
	}
}