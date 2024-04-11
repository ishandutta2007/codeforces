#include<bits/stdc++.h>
using namespace std;
#define MN 2005
#define eps 1e-5
#define x first
#define y second
#define mp make_pair
int n,m;
double x[MN],y[MN],X[MN],Y[MN];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>X[i]>>Y[i];
	}
	X[n+1]=X[1];Y[n+1]=Y[1];
	for(int i=1;i<=m;++i){
		double a,b,c,d;
		cin>>a>>b>>c>>d;
		c-=a;d-=b;
		double L=sqrt(c*c+d*d+1e-11),SIN=d/L,COS=c/L;
		for(int j=1;j<=n+1;++j){
			double xx=X[j]-a,yy=Y[j]-b;
			x[j]=xx*COS+yy*SIN;
			y[j]=yy*COS-xx*SIN;
		}
		vector<double>pt;
		vector<pair<double,double> >tag;
		pt.clear();tag.clear();
		for(int j=1;j<=n;++j){			
			if(fabs(y[j])<=eps&&fabs(y[j+1])<=eps){
				if(x[j]>x[j+1])tag.push_back(mp(x[j+1],x[j]));
				else tag.push_back(mp(x[j],x[j+1]));
			}
			else if((y[j]<-1e-10)^(y[j+1]<-1e-10)){
				double pos=x[j]+(x[j+1]-x[j])*fabs(y[j]/(y[j+1]-y[j]));
//				cerr<<"getpos: "<<pos<<endl;
				pt.push_back(pos);
			}
		}
		sort(tag.begin(),tag.end());
		sort(pt.begin(),pt.end());
		int p=0;
		double mx=-1e9,ans=0;
		assert(pt.size()%2==0);
		while(pt.size()&&p<tag.size()&&tag[p].x<=pt[0]){	
			if(tag[p].y>mx){
				ans+=min(pt[0],tag[p].y)-max(mx,tag[p].x);
				mx=tag[p].y;
			}
			p++;
		}
		for(int i=0;i<(int)pt.size()-1;++i){
//			cerr<<"? "<<pt[i]<<" "<<pt[i+1]<<endl;
			while(p<tag.size()&&tag[p].x<=pt[i]){
				mx=max(mx,tag[p].y);p++;
			}
			if(i+1&1){
				ans+=pt[i+1]-pt[i];
				mx=max(mx,pt[i+1]);
//				cerr<<"OK "<<" "<<pt[i+1]-pt[i]<<endl;
			}
			else{
				if(mx>pt[i])ans+=mx-pt[i];
				while(p<tag.size()&&tag[p].x<=pt[i+1]){
					if(tag[p].y>mx){
						ans+=min(pt[i+1],tag[p].y)-max(mx,tag[p].x);
						mx=tag[p].y;
					}
					p++;
				}
			}
		}
		for(int i=p;i<tag.size();++i){
			if(tag[i].y>mx){
				ans+=tag[i].y-max(mx,tag[i].x);
				mx=tag[i].y;
			}
		}
		printf("%.12lf\n",ans);
	}
	return 0;
}