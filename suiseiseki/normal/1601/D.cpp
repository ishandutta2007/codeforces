#include <cstdio>
#include <algorithm>
const int Maxn=500000;
int n,d;
struct Segment{
	int s,a;
	Segment(int _s=0,int _a=0){
		s=_s,a=_a;
	}
}seg_1[Maxn+5],seg_2[Maxn+5];
int seg_1_len,seg_2_len;
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++){
		int s,a;
		scanf("%d%d",&s,&a);
		if(s<d){
			continue;
		}
		if(s>=a){
			seg_2[++seg_2_len]=Segment(s,a);
		}
		else{
			seg_1[++seg_1_len]=Segment(s,a);
		}
	}
	std::sort(seg_1+1,seg_1+1+seg_1_len,[&](Segment a,Segment b){return a.a==b.a?a.s<b.s:a.a<b.a;});
	std::sort(seg_2+1,seg_2+1+seg_2_len,[&](Segment a,Segment b){return a.s<b.s;});
	int ans=seg_2_len;
	for(int i=1,j=1;i<=seg_1_len;i++){
		while(j<=seg_2_len&&seg_2[j].s<seg_1[i].a){
			d=std::max(d,seg_2[j].a);
			j++;
		}
		if(d<=seg_1[i].s){
			d=std::max(d,seg_1[i].a);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}