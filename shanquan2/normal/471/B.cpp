#include<cstdio>
#include<algorithm>
using namespace std;

struct task{
	int id,x;
}a[2000];
bool cmp(const task &x,const task &y){
	return x.x<y.x;
}
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i].x);
		a[i].id=i+1;
	}
	sort(a,a+n,cmp);
	int i=0;
	bool f=0;int s=1;
	while(i<n){
		int i0=i;
		while(i<n && a[i].x==a[i0].x)i++;
		if(i-i0>2)f=1;
		if(i-i0==2 && s<3)s*=2;
	}
	if(!f && s<3)printf("NO\n");
	else {
		printf("YES\n");
		if(f){
			int i=0,i0;
			while(i<n){
				i0=i;
				while(i<n && a[i].x==a[i0].x)i++;
				if(i-i0>2)break;
			}
			if(i0>0)printf("%d",a[0].id);
			
			for(int i=1;i<i0;i++)printf(" %d",a[i].id);
			if(i0>0)printf(" ");
			printf("%d %d %d",a[i0].id,a[i0+1].id,a[i0+2].id);
			for(int i=i0+3;i<n;i++)printf(" %d",a[i].id);printf("\n");
			
			if(i0>0)printf("%d",a[0].id);
			for(int i=1;i<i0;i++)printf(" %d",a[i].id);
			if(i0>0)printf(" ");
			printf("%d %d %d",a[i0].id,a[i0+2].id,a[i0+1].id);
			for(int i=i0+3;i<n;i++)printf(" %d",a[i].id);printf("\n");
			
			if(i0>0)printf("%d",a[0].id);
			for(int i=1;i<i0;i++)printf(" %d",a[i].id);
			if(i0>0)printf(" ");
			printf("%d %d %d",a[i0+1].id,a[i0].id,a[i0+2].id);
			for(int i=i0+3;i<n;i++)printf(" %d",a[i].id);printf("\n");
		}else{
			int i=0,i1=-1,i2;
			while(i<n){
				int i0=i;
				while(i<n && a[i].x==a[i0].x)i++;
				if(i-i0==2)
					if(i1==-1)i1=i0;else i2=i0;
			}
			if(i1>0)printf("%d",a[0].id);
			
			for(int i=1;i<i1;i++)printf(" %d",a[i].id);
			if(i1>0)printf(" ");
			printf("%d %d",a[i1].id,a[i1+1].id);
			for(int i=i1+2;i<i2;i++)printf(" %d",a[i].id);
			printf(" %d %d",a[i2].id,a[i2+1].id);
			for(int i=i2+2;i<n;i++)printf(" %d",a[i].id);printf("\n");
			
			if(i1>0)printf("%d",a[0].id);
			for(int i=1;i<i1;i++)printf(" %d",a[i].id);
			if(i1>0)printf(" ");
			printf("%d %d",a[i1].id,a[i1+1].id);
			for(int i=i1+2;i<i2;i++)printf(" %d",a[i].id);
			printf(" %d %d",a[i2+1].id,a[i2].id);
			for(int i=i2+2;i<n;i++)printf(" %d",a[i].id);printf("\n");
			
			if(i1>0)printf("%d",a[0].id);
			for(int i=1;i<i1;i++)printf(" %d",a[i].id);
			if(i1>0)printf(" ");
			printf("%d %d",a[i1+1].id,a[i1].id);
			for(int i=i1+2;i<i2;i++)printf(" %d",a[i].id);
			printf(" %d %d",a[i2].id,a[i2+1].id);
			for(int i=i2+2;i<n;i++)printf(" %d",a[i].id);printf("\n");
			
		}
	}
	return 0;
}