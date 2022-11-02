#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

char s[1100000];
char t[1100000];

#define MOD 101LL

long long pw[1100000];
vector <int> res;
long long h1[1100000];
long long h2[1100000];

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	gets(s);
	gets(t);

	long long h=0;
	int k=strlen(t);
	for (int i=0; i<k; i++)
		h*=MOD, h+=(long long)(t[i]-'a'+1);

	pw[0]=1;
	for (int i=1; i<1100000; i++)
		pw[i]=pw[i-1]*MOD;

	h1[0]=(long long)(s[0]-'a'+1);
	for (int i=1; i<k+1; i++)
		h1[i]=h1[i-1]*MOD+(long long)(s[i]-'a'+1);

	h2[k]=(long long)(s[k]-'a'+1);

	for (int i=k-1; i>=0; i--)
		h2[i]=(long long)(s[i]-'a'+1)*pw[k-i]+h2[i+1];

	if (h2[1]==h) res.push_back(1);

	for (int i=1; i<k; i++){
		long long cur=h1[i-1]*pw[k-i]+h2[i+1];
		if (cur==h) res.push_back(i+1);
	}

	if (h1[k-1]==h) res.push_back(k+1);
	printf("%d\n",(int)(res.size()));

	for (int i=0; i<(int)res.size(); i++)
		printf("%d ",res[i]);
	printf("\n");

	return 0;
}