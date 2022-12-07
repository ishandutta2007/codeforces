#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

char a[2222];
int len,ans=0,h=0,st=0,sp[2000222][26],n,f[2000222];
int l[11],r[11];
string s[11];
vector<int>v[11];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	len = strlen(a);
	scanf("%d\n",&n);
	for (int i=0;i<n;i++)cin >> s[i] >> l[i] >> r[i];
	for (int x=0;x<len;x++){
		for (int i=0;i<n;i++){
			v[i].clear();
			for (int j=0;j<s[i].size();j++)if (s[i][j] == a[x])v[i].pb(j);
		}
		h=0;
		for (int y=x;y<len;y++){
			if (sp[h][a[y]-'a'] == 0){
				st++;
				sp[h][a[y]-'a'] = st;
				h =st;
			} else h = sp[h][a[y]-'a'];
			if (y!=x)for (int i=0;i<n;i++){
				for (int j=v[i].size()-1;j>=0;j--)
				if (v[i][j] + 1 == s[i].size() || s[i][v[i][j]+1] != a[y]){
					v[i][j] = v[i][v[i].size()-1];
					v[i].pop_back();
				}else v[i][j] ++;
			}
//			cout << x << " " << y << " " << v[0].size() << " " << v[1].size() << endl;
			int ok = 1;
			for (int i=0;i<n;i++)if (l[i] > v[i].size() || v[i].size() > r[i]) ok = 0;
			if (ok){
				if (!f[h])ans++;
				f[h]=1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}