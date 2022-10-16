    #include<bits/stdc++.h>
    #define rep(i,a,b) for (register int i=a;i<=b;++i)
    #define req(i,a,b) for (register int i=a;i>=b;--i)
    using namespace std;
    long long T,x,y,c[7],d[7],ans,f;
    int main()
    {
        cin>>T;
        while(T--)
        {
            ans=0;
            cin>>y>>x;
            rep(i,1,6) cin>>c[i];
            d[1]=min(c[1],c[6]+c[2]);
            rep(i,2,5) d[i]=min(c[i],c[i-1]+c[i+1]);
            d[6]=min(c[6],c[5]+c[1]);
            rep(i,1,6) c[i]=d[i];
            d[6]=min(c[6],c[5]+c[1]);
            req(i,5,2) d[i]=min(c[i],c[i-1]+c[i+1]);
            d[1]=min(c[1],c[6]+c[2]);
            rep(i,1,6) c[i]=d[i];
            if (x<0&&y<0) f=min(-x,-y),ans+=c[4]*f,x+=f,y+=f;
            if (x>0&&y>0) f=min(x,y),ans+=c[1]*f,x-=f,y-=f;
            if (x<0) ans+=c[5]*(-x);
            else ans+=c[2]*x;
            if (y<0) ans+=c[3]*(-y);
            else ans+=c[6]*y;
            cout<<ans<<'\n';
        }
        return 0;
    }