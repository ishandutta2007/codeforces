#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,tim[26];
char S[100005];
int main(){
	scanf("%d%s",&n,S);
	if(n==1)return puts("Yes"),0;
	for(int i=0;i<n;i++)
	tim[S[i]-'a']++;
	for(int i=0;i<26;i++)
	if(tim[i]>1)return puts("Yes"),0;
	puts("No");
}