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
#define ppb pop_back

#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
int n,m,ans;
char a[100][100];
char tk[100][100];
char aa[100][100];
char tk1[100][100];

bool bukv(char a){
	return ((a>='a' && a<='z')||(a>='A' && a<='Z'));
}
int v[1000][3];
int ws[100][100];
int cnt;
int x1[100];
int y1[100];
int cc[100];
int ff=0;
bool check(){
	ff++;
	for (char c='a';c<='z';c++){
		int i=c;
		if (v[i][2]==2){
			if (ws[min(v[i][0],v[i][1])][max(v[i][0],v[i][1])]==ff) return false;
			ws[min(v[i][0],v[i][1])][max(v[i][0],v[i][1])]=ff;
		}
	}
	for (char c='A';c<='Z';c++){
		int i=c;
		if (v[i][2]==2){
			if (ws[min(v[i][0],v[i][1])][max(v[i][0],v[i][1])]==ff) return false;
			ws[min(v[i][0],v[i][1])][max(v[i][0],v[i][1])]=ff;
		}
	}
	return true;
}
void obr(){
	cnt=0;
	for (int x=0;x<n;x++)
		for (int y=0;y<m;y++){
			if (bukv(tk1[x][y]) && bukv(tk1[x+1][y]) && bukv(tk1[x][y+1]) && bukv(tk1[x+1][y+1])){						
				tk1[x][y]='0';
				tk1[x][y+1]='0';
				tk1[x+1][y]='0';
				tk1[x+1][y+1]='0';
				x1[cnt]=x;
				y1[cnt]=y;
				cnt++;
			} 
		}
}
void bct(int k){
	if (k==cnt){
		ans++;
		if (ans==1){
			for (int i=0;i<n;i++){
				for (int j=0;j<m;j++)
					aa[i][j]=tk[i][j];
			}
		}
		return;
	}
	int x,y;
	for (int i=0;i<=6;i++) if (cc[i]<2){
		cc[i]++;
		x=x1[k];
		y=y1[k];
		v[a[x][y]][v[a[x][y]][2]++]=i;
        v[a[x+1][y]][v[a[x+1][y]][2]++]=i;
		v[a[x][y+1]][v[a[x][y+1]][2]++]=i;
		v[a[x+1][y+1]][v[a[x+1][y+1]][2]++]=i;
		tk[x][y]=i+'0';
		tk[x][y+1]=i+'0';
		tk[x+1][y]=i+'0';
		tk[x+1][y+1]=i+'0';
		if (check()){
			bct(k+1);
		}
		cc[i]--;
		v[a[x][y]][2]--;
		v[a[x+1][y]][2]--;
		v[a[x][y+1]][2]--;
		v[a[x+1][y+1]][2]--;
		if (k==0) break;
	}
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			tk[i][j]=a[i][j];
			tk1[i][j]=a[i][j];
		}
	}
	ans=0;
	obr();
	bct(0);
	printf("%d\n",ans*7);
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%c",aa[i][j]);
		}
		printf("\n");
	}
    return 0;
}