#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
#define x first
#define y second
typedef long long ll;
typedef pair<double,double> P;
const double STD=1e-12;  
const double PI=acos(-1.0); 
int n,q;
P node[MAXN];
double dis[MAXN],ang[MAXN];
double Area(P p0 ,P p1 ,P p2 )
{
    double area = 0 ;
    area =  p0.x * p1.y + p1.x * p2.y + p2.x * p0.y - p1.x * p0.y - p2.x * p1.y - p0.x * p2.y;
    return area / 2 ;  
}

double Cal_Alpha (const P &o, const P &a, const P &b)  
{  
    P t1,t2;  
    double theta;  
    t1.x = a.x - o.x, t1.y = a.y - o.y;  
    t2.x = b.x - o.x, t2.y = b.y - o.y;  
    theta = atan2((double)t2.y, (double)t2.x) - atan2((double)t1.y, (double)t1.x);  
    if (theta < -STD)  
        theta += 2.0 * PI;  
    return theta;  
}  
int main()
{  
    scanf("%d%d",&n,&q);  
    double S,tS,sx,sy;   
    for(int i=0;i<n;i++)  
    	scanf("%lf%lf",&node[i].x,&node[i].y); 
    S=0.;sx=0.;sy=0.; 
    for(int i=2;i<n;i++)
    {  
        tS=Area(node[0],node[i-1],node[i]);  
        S+=tS;  
        sx+=tS*(node[0].x+node[i-1].x+node[i].x);  
        sy+=tS*(node[0].y+node[i-1].y+node[i].y);  
    }   
    double dx=sx/S/3,dy=sy/S/3;
    P center;
    center.x=dx;center.y=dy;
    for(int i=0;i<n;i++)
    	dis[i]=sqrt((node[i].x-dx)*(node[i].x-dx)+(node[i].y-dy)*(node[i].y-dy));
    ang[0]=0;
    for(int i=1;i<n;i++)
    {
    	ang[i]=Cal_Alpha(center,node[0],node[i]);
    	//printf("%.10lf\n",ang[i]/PI*180);
    }
    int id0=0,id1=1,hanging=-1;
    for(int i=0;i<q;i++)
    {
    	int type;
    	scanf("%d",&type);
    	if(type==1)
    	{
    		int t,f;
    		scanf("%d%d",&t,&f);
    		t--;f--;
    		if(t==id0)
    		{
    			center.x=node[id1].x;
    			center.y=node[id1].y-dis[id1];
    			//printf("%.10lf %.10lf\n",center.x,center.y);
    			id0=f;
    			double _ang=ang[id1]-ang[id0];
    			//printf("%.10lf\n",_ang/PI*180);
    			double nx=dis[id0]*sin(_ang),ny=dis[id0]*cos(_ang);
    			node[id0].x=center.x+nx;
    			node[id0].y=center.y+ny;
    			hanging=1;
    		}
    		else
    		{
    			center.x=node[id0].x;
    			center.y=node[id0].y-dis[id0];
    			id1=f;
    			double _ang=ang[id0]-ang[id1];
    			double nx=dis[id1]*sin(_ang),ny=dis[id1]*cos(_ang);
    			node[id1].x=center.x+nx;
    			node[id1].y=center.y+ny;
    			hanging=0;
    		}
    	}
    	else
    	{
    		int id;
    		scanf("%d",&id);
    		id--;
    		if(hanging==-1)
    		{
    			printf("%.10lf %.10f\n",node[id].x,node[id].y);
    			continue;
    		}
    		else if (hanging==0)
    		{
	    		double _ang=ang[id0]-ang[id];
	    		//printf("%.10lf\n",_ang/PI*180);
	    		double nx=dis[id]*sin(_ang),ny=dis[id]*cos(_ang);
	    		printf("%.10lf %.10f\n",center.x+nx,center.y+ny);
	    	}
	    	else
	    	{
	    		double _ang=ang[id1]-ang[id];
	    		//printf("%.10lf\n",_ang/PI*180);
	    		double nx=dis[id]*sin(_ang),ny=dis[id]*cos(_ang);
	    		printf("%.10lf %.10f\n",center.x+nx,center.y+ny);
	    	}
    	}
    }
    return 0;  
}