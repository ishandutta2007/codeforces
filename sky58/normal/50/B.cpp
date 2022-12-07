#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int kei[0x100];
int de(char a){
	if(a<='z' && a>='a') return (a-'a');
	else return (a-'0')+26;
}
int main()
{
	int i;string s;
	lint out=0;
//	for(i=0;i<48;i++) kei[i]=0;
	memset(kei,0,sizeof(kei));
	cin >> s;
	for(i=0;i<s.size();i++) kei[s[i]]++;
	for(i=0;i<0x100;i++) out+=(lint)kei[i]*kei[i];
	cout<<out<<endl;return 0;
}