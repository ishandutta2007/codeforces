#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=300003,INF=1<<30;

struct change{
    ll point;
    ll sum;
    ll size;
    
    bool operator<(const change &another) const
    {
        return point<another.point;
    };
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N),diff;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(all(A));
    
    A.erase(unique(all(A)),A.end());
    
    for(int i=1;i<A.size();i++) diff.push_back(A[i]-A[i-1]);
    
    sort(all(diff));
    
    //for(ll a:diff) cout<<a<<endl;
    
    vector<change> when;
    
    when.push_back({0,ll(A.size()),ll(A.size())});
    
    for(int i=0;i<diff.size();i++){
        int j=i;
        while(j<diff.size()&&diff[i]==diff[j]) j++;
        j--;
        change p=when.back();
        
        change pu;
        pu.point=diff[i];
        pu.size=A.size()-(j+1);
        pu.sum=p.sum+(pu.point-p.point)*p.size-(j-i+1);
        
        when.push_back(pu);
        
        i=j;
    }
    
    //for(change c:when) cout<<c.point<<" "<<c.sum<<" "<<c.size<<endl;
    
    int Q;cin>>Q;
    
    while(Q--){
        ll l,r;cin>>l>>r;
        ll d=r-l;
        
        auto it=lower_bound(all(when),change{d,0,0});
        
        if(it==when.end()) it--;
        else{
            if((*it).point!=d) it--;
        }
        
        cout<<(*it).sum+(d-(*it).point)*(*it).size<<endl;
    }
}