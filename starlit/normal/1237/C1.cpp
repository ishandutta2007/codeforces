#include<bits/stdc++.h>
const int N=50004;
using namespace std;
int n,m,k;
struct pt{
	int x,y,z,no;
}p[N],q[N],r[N];
bool cmp(pt a,pt b){
	return a.x==b.x?a.y==b.y?a.z<b.z:a.y<b.y:a.x<b.x;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z),p[i].no=i+1;
	sort(p,p+n,cmp);
	for(int i=0;i<n;i++)
	if(i<n-1&&p[i].x==p[i+1].x&&p[i].y==p[i+1].y){
		printf("%d %d\n",p[i].no,p[i+1].no);
		i++;
	}
	else q[m++]=p[i];
	for(int i=0;i<m;i++)
	if(i<m-1&&q[i].x==q[i+1].x){
		printf("%d %d\n",q[i].no,q[i+1].no);
		i++;
	}
	else r[k++]=q[i];
	for(int i=0;i<k;i+=2)
	printf("%d %d\n",r[i].no,r[i+1].no);
}