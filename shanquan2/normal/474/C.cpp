#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int x1,y1,a1,b1;
        int x2,y2,a2,b2;
        int x3,y3,a3,b3;
        int x4,y4,a4,b4;
        scanf("%d%d%d%d",&x1,&y1,&a1,&b1);
        scanf("%d%d%d%d",&x2,&y2,&a2,&b2);
        scanf("%d%d%d%d",&x3,&y3,&a3,&b3);
        scanf("%d%d%d%d",&x4,&y4,&a4,&b4);
        int ans=100;
        int u[5],v[5];
        for(int i=0;i<4;i++){
            if(i==0)u[1]=x1,v[1]=y1;
            if(i==1)u[1]=a1+b1-y1,v[1]=x1+b1-a1;
            if(i==2)u[1]=2*a1-x1,v[1]=2*b1-y1;
            if(i==3)u[1]=y1-b1+a1,v[1]=a1+b1-x1;
        for(int j=0;j<4;j++){
            if(j==0)u[2]=x2,v[2]=y2;
            if(j==1)u[2]=a2+b2-y2,v[2]=x2+b2-a2;
            if(j==2)u[2]=2*a2-x2,v[2]=2*b2-y2;
            if(j==3)u[2]=y2-b2+a2,v[2]=a2+b2-x2;
        for(int k=0;k<4;k++){
            if(k==0)u[3]=x3,v[3]=y3;
            if(k==1)u[3]=a3+b3-y3,v[3]=x3+b3-a3;
            if(k==2)u[3]=2*a3-x3,v[3]=2*b3-y3;
            if(k==3)u[3]=y3-b3+a3,v[3]=a3+b3-x3;
        for(int l=0;l<4;l++){
            if(l==0)u[4]=x4,v[4]=y4;
            if(l==1)u[4]=a4+b4-y4,v[4]=x4+b4-a4;
            if(l==2)u[4]=2*a4-x4,v[4]=2*b4-y4;
            if(l==3)u[4]=y4-b4+a4,v[4]=a4+b4-x4;
            long long dis[20],t=0;
            for(int a=1;a<=3;a++)
                for(int b=a+1;b<=4;b++)
                    dis[t++]=(long long)(u[a]-u[b])*(u[a]-u[b])+(long long)(v[a]-v[b])*(v[a]-v[b]);
            sort(dis,dis+t);
//          if(i+j+k+l==8)printf("%d %d %d %d %d %d\n",dis[0],dis[1],dis[2],dis[3],dis[4],dis[5]);
            if(dis[0]==dis[1] && dis[1]==dis[2] && dis[2]==dis[3] && dis[5]==dis[4] && dis[0]!=0)
                if(i+j+k+l<ans)ans=i+j+k+l;
        }
        }
        }
        }
        if(ans>=100)printf("-1\n");else printf("%d\n",ans);
    }
    return 0;
}