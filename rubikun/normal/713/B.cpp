#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=1<<30;

int ask(int l,int r,int u,int d){
    if(l>r||u>d) return 0;
    cout<<"? "<<l<<" "<<u<<" "<<r<<" "<<d<<endl;
    int x;cin>>x;
    return x;
}

void output(int l1,int r1,int u1,int d1,int l2,int r2,int u2,int d2){
    cout<<"! "<<l1<<" "<<u1<<" "<<r1<<" "<<d1<<" "<<l2<<" "<<u2<<" "<<r2<<" "<<d2<<endl;
    exit(0);
}

int main(){
    
    int N;cin>>N;
    int l1,l2,r1,r2;
    
    {
        int left=0,right=N;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(1,mid,1,N);
            if(res==2) right=mid;
            else left=mid;
        }
        
        r2=right;
        
        int xx=ask(1,left,1,N);
        if(xx==0){
            r1=right;
        }else{
            left=0;right--;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(1,mid,1,N);
                if(res==1) right=mid;
                else left=mid;
            }
            r1=right;
        }
    }
    
    {
        int left=1,right=N+1;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(mid,N,1,N);
            if(res==2) left=mid;
            else right=mid;
        }
        
        l1=left;
        
        int xx=ask(right,N,1,N);
        if(xx==0){
            l2=left;
        }else{
            left++;right=N+1;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(mid,N,1,N);
                if(res==1) left=mid;
                else right=mid;
            }
            l2=left;
        }
    }
    
    if(l1==l2&&r1==r2){
        int l=l1,r=r1;
        int left=0,right=N;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l,r,1,mid);
            if(res>=1) right=mid;
            else left=mid;
        }
        int d1=right;
        left=0;right=N;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l,r,1,mid);
            if(res==2) right=mid;
            else left=mid;
        }
        int d2=right;
        
        left=1;right=N+1;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l,r,mid,N);
            if(res==2) left=mid;
            else right=mid;
        }
        int u1=left;
        left=1;right=N+1;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l,r,mid,N);
            if(res>=1) left=mid;
            else right=mid;
        }
        int u2=left;
        
        output(l,r,u1,d1,l,r,u2,d2);
        
    }
    
    if(l1==l2){
        //int l=l1,r=r1;
        int left=0,right=N;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l1,r1,1,mid);
            if(res>=1) right=mid;
            else left=mid;
        }
        int d1=right;
        
        left=1;right=N+1;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l1,r1,mid,N);
            if(res>=1) left=mid;
            else right=mid;
        }
        int u1=left;
        
        int u2,d2;
        if(ask(l2,r2,d1+1,N)){
            left=d1;right=N;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(l2,r2,d1+1,mid);
                if(res>=1) right=mid;
                else left=mid;
            }
            d2=right;
            left=d1+1;right=N+1;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(l2,r2,mid,N);
                if(res>=1) left=mid;
                else right=mid;
            }
            u2=left;
        }else{
            left=0;right=u1-1;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(l2,r2,1,mid);
                if(res>=1) right=mid;
                else left=mid;
            }
            d2=right;
            left=1;right=u1;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(l2,r2,mid,u1-1);
                if(res>=1) left=mid;
                else right=mid;
            }
            u2=left;
        }
        
        output(l1,r1,u1,d1,l2,r2,u2,d2);
        
    }
    
    if(r1==r2){
        //int l=l1,r=r1;
        swap(l1,l2);
        swap(r1,r2);
        int left=0,right=N;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l1,r1,1,mid);
            if(res>=1) right=mid;
            else left=mid;
        }
        int d1=right;
        
        left=1;right=N+1;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l1,r1,mid,N);
            if(res>=1) left=mid;
            else right=mid;
        }
        int u1=left;
        
        int u2,d2;
        if(ask(l2,r2,d1+1,N)){
            left=d1;right=N;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(l2,r2,d1+1,mid);
                if(res>=1) right=mid;
                else left=mid;
            }
            d2=right;
            left=d1+1;right=N+1;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(l2,r2,mid,N);
                if(res>=1) left=mid;
                else right=mid;
            }
            u2=left;
        }else{
            left=0;right=u1-1;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(l2,r2,1,mid);
                if(res>=1) right=mid;
                else left=mid;
            }
            d2=right;
            left=1;right=u1;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(l2,r2,mid,u1-1);
                if(res>=1) left=mid;
                else right=mid;
            }
            u2=left;
        }
        
        output(l1,r1,u1,d1,l2,r2,u2,d2);
    }
    
    if(ask(l2,r1,1,N)==0){
        int left=0,right=N;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l1,r1,1,mid);
            if(res>=1) right=mid;
            else left=mid;
        }
        int d1=right;
        
        left=1;right=N+1;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l1,r1,mid,N);
            if(res>=1) left=mid;
            else right=mid;
        }
        int u1=left;
        
        left=0;right=N;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l2,r2,1,mid);
            if(res>=1) right=mid;
            else left=mid;
        }
        int d2=right;
        
        left=1;right=N+1;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l2,r2,mid,N);
            if(res>=1) left=mid;
            else right=mid;
        }
        int u2=left;
        
        output(l1,r1,u1,d1,l2,r2,u2,d2);
    }else{
        swap(l1,l2);
        
        int left=0,right=N;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l1,r1,1,mid);
            if(res>=1) right=mid;
            else left=mid;
        }
        int d1=right;
        
        left=1;right=N+1;
        while(right-left>1){
            int mid=(left+right)/2;
            int res=ask(l1,r1,mid,N);
            if(res>=1) left=mid;
            else right=mid;
        }
        int u1=left;
        
        int u2,d2;
        if(ask(l2,r2,d1+1,N)){
            left=d1;right=N;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(l2,r2,d1+1,mid);
                if(res>=1) right=mid;
                else left=mid;
            }
            d2=right;
            left=d1+1;right=N+1;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(l2,r2,mid,N);
                if(res>=1) left=mid;
                else right=mid;
            }
            u2=left;
        }else{
            left=0;right=u1-1;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(l2,r2,1,mid);
                if(res>=1) right=mid;
                else left=mid;
            }
            d2=right;
            left=1;right=u1;
            while(right-left>1){
                int mid=(left+right)/2;
                int res=ask(l2,r2,mid,u1-1);
                if(res>=1) left=mid;
                else right=mid;
            }
            u2=left;
        }
        
        output(l1,r1,u1,d1,l2,r2,u2,d2);
    }
}