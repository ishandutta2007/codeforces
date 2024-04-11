#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
char a[2000][2000];
int b[2000][2000];
char ff[2000*2000];
int ws[2000];
vector<int> sd[2000*2000];
int n,m;
int cnt;
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%s",a[i]);
	}    
	cnt=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)if (a[i][j]=='.'){
			bool bol=false;
			if (i>0 && a[i-1][j]=='.') bol=true;
			if (j>0 && a[i][j-1]=='.') bol=true;
			if (a[i+1][j]=='.') bol=true;
			if (a[i][j+1]=='.') bol=true;
			if(!bol){
				cout<<"-1"<<endl;
				return 0;
			}
		}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++){
			if (a[i][j]=='.' && a[i][j+1]=='.'){
				b[i][j]=++cnt;
				b[i][j+1]=cnt;
				a[i][j]='#';
				a[i][j+1]='#';
			}
			if (a[i][j]=='.' && a[i+1][j]=='.'){
				b[i][j]=++cnt;
				b[i+1][j]=cnt;
				a[i][j]='#';
				a[i+1][j]='#';
			}
		}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)if (a[i][j]=='.'){
			bool bol=false;
			if (i>0 && a[i-1][j]=='.') bol=true;
			if (j>0 && a[i][j-1]=='.') bol=true;
			if (a[i+1][j]=='.') bol=true;
			if (a[i][j+1]=='.') bol=true;
			if(!bol){
				a[i][j]='#';
				if (i>0 && b[i-1][j]!=0) b[i][j]=b[i-1][j];
				if (j>0 && b[i][j-1]!=0) b[i][j]=b[i][j-1];
				if (b[i+1][j]!=0) b[i][j]=b[i+1][j];
				if (b[i][j+1]!=0) b[i][j]=b[i][j+1];
			}
			
		}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)if (b[i][j]!=0){
			if (i>0 && b[i-1][j]!=0) if (b[i-1][j]!=b[i][j]) sd[b[i][j]].pb(b[i-1][j]);
			if (j>0 && b[i][j-1]!=0) if (b[i][j-1]!=b[i][j]) sd[b[i][j]].pb(b[i][j-1]);
			if (b[i+1][j]!=0) if (b[i+1][j]!=b[i][j]) sd[b[i][j]].pb(b[i+1][j]);
			if (b[i][j+1]!=0) if (b[i][j+1]!=b[i][j]) sd[b[i][j]].pb(b[i][j+1]);
		}
	ff[0]='#';
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)if (ff[b[i][j]]==0){
			cnt++;
			for (int k=0;k<(int)sd[b[i][j]].size();k++){
				ws[ff[sd[b[i][j]][k]]]=cnt;
			}
			for (int k='1';k<='9';k++) if (ws[k]!=cnt){
				ff[b[i][j]]=k;
				break;
			}
		}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++) printf("%c",ff[b[i][j]]);
		printf("\n");
    }

    return 0;
}