#include<cstdio>
using namespace std;

const int ct[10][4]={{0,0,0,0},
					 {1,0,0,0},
					 {0,1,0,0},
					 {2,0,0,0},
					 {0,0,1,0},
					 {1,1,0,0},
					 {0,0,0,1},
					 {3,0,0,0},
					 {0,2,0,0}};
const int p[4]={2,3,5,7};
int cnt[4];
char st[20];
int main(){
	int n;scanf("%d",&n);
	scanf("%s",st);
	for(int i=0;i<n;i++)
		for(int j=0;j<st[i]-'0';j++)
			for(int k=0;k<4;k++)
				cnt[k]+=ct[j][k];
	for(int i=3;i>=0;i--)if(cnt[i]>0){
		for(int j=0;j<cnt[i];j++)printf("%d",p[i]);
		for(int k=0;k<p[i];k++)
			for(int j=0;j<4;j++)
				cnt[j]-=ct[k][j]*cnt[i];
	}printf("\n");
	return 0;
}