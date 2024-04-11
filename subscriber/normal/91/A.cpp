#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

char a[11111],b[1111111];
int n,m,d[11111][333],f1[1111111],f2[1111111];
                        
int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	gets(b);
	n=strlen(a);
	m=strlen(b);
	for (char i='a';i<='z';i++)d[n][i]=-1;
	for (int i=n-1;i>=0;i--){
		for (char j='a';j<='z';j++)d[i][j]=d[i+1][j];
		d[i][a[i]]=i;
	}
	memset(f1,63,sizeof(f1));
	memset(f2,63,sizeof(f2));
	if (d[0][b[0]]==-1){
		puts("-1");
		return 0;
	}
	f1[0]=1;
	f2[0]=d[0][b[0]];
	for (int i=1;i<m;i++){
		if (f1[i-1]>m)continue;
		if (d[f2[i-1]+1][b[i]]!=-1){
			f1[i]=f1[i-1];
			f2[i]=d[f2[i-1]+1][b[i]];
		}else if (d[0][b[i]]!=-1){
			f1[i]=f1[i-1]+1;
			f2[i]=d[0][b[i]];
		}
	}
	if (f1[m-1]>m)puts("-1");else cout << f1[m-1] << endl;
	return 0;
}