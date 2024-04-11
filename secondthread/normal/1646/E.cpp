#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool hit[1000001] = {0};

ll powSlow(int base, int exp, int max) {
    ll ans=1;
    for (int i=0; i<exp; i++) {
        ans*=base;
        if (ans>max) return max;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int height, width;
    cin>>height>>width;
    // width=1000000;
    // height=1000000;
    ll ans=1;

    hit[1]=true;
    int innerTimes=0;
    for (int y=2; y<=height; y++) {
        if (hit[y]) continue;
        int maxPow=1;
        hit[y]=true;
        while (powSlow(y, maxPow+1, height+1)<=height) {
            maxPow++;
            hit[powSlow(y, maxPow, height+1)]=true;
        }
        
        if (maxPow==1) {
            ans+=width;
            continue;
        }
        if(maxPow==2) {
            ans+=width;
            ans+=width-width/2;
            continue;
        }
        if (maxPow==3) {
            ans+=width;
            
            ans+=width-width/2;
            
            ans+=width;
            ans-=width/3;
            ans-=width/3;
            ans+=width/6;
            continue;
        }
        if (maxPow==4) {
				ans+=width;
				
				ans+=width-width/2;
				
				ans+=width;
				ans-=width/3;
				ans-=width/3;
				ans+=width/6;
				
				ans+=width;
				
				ans-=width/4;
				
				ans-=width/2;
				ans+=width/4;
				
				//every 12
				ans-=width/4;
				ans+=width/6;
				continue;
			}
        //~100 times
        
        ans+=width;

        ans+=width-width/2;
        ans+=width;

        ans-=width/3;
        ans-=width/3;
        ans+=width/6;
        
        ans+=width;
        
        ans-=width/4;

        ans-=width/2;
        ans+=width/4;
        
        //every 12
        ans-=width/4;
        ans+=width/6;
        for (int exp=5; exp<=maxPow; exp++) { //at most 20
            innerTimes++;
            for (int expMultiplier=(width+1)/exp; expMultiplier<=width; expMultiplier++) {
                ll toEval=exp*expMultiplier;
                //have we seen this before?
                if (toEval<=width) continue;
                if ((toEval&1)==0 && toEval>>1<=width) continue;
                bool broken=false;
                for (int i=3; i<exp; i++) {
                    if (toEval%i==0 && toEval/i<=width) {
                        broken=true;
                        break;
                    }
                }
                if (!broken)
                    ans++;
            }
        }
    }
    
    // cout<<innerTimes<<'\n';
    cout<<ans<<'\n';
    return 0;
}