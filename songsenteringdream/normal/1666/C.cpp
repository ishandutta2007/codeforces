#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
int cnt,n,X1[9],Y1[9],X2[9],Y2[9];pair<int,int> p[4];
int main(){
	for(int i=1;i<4;++i) scanf("%d%d",&p[i].first,&p[i].second);
	sort(p+1,p+4);
	Y1[++cnt]=min(min(p[1].second,p[2].second),p[3].second);
	Y2[cnt]=max(max(p[1].second,p[2].second),p[3].second);
	X1[cnt]=X2[cnt]=p[2].first;
	X1[++cnt]=p[1].first;X2[cnt]=p[2].first;
	Y1[cnt]=Y2[cnt]=p[1].second;
	X1[++cnt]=p[2].first;X2[cnt]=p[3].first;
	Y1[cnt]=Y2[cnt]=p[3].second;
	for(int i=1;i<=cnt;++i) if(X1[i]-X2[i]||Y1[i]-Y2[i]) ++n;
	printf("%d\n",n);
	for(int i=1;i<=cnt;++i) if(X1[i]-X2[i]||Y1[i]-Y2[i]) printf("%d %d %d %d\n",X1[i],Y1[i],X2[i],Y2[i]); 
	return 0;
}