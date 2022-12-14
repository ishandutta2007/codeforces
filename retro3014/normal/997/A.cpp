#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;
typedef long long ll;

int N;
ll A, B;
string str;
deque<char> dq;
ll ans;

int main(){
    cin>>N>>A>>B;
    cin>>str;
    dq.push_back(str.at(0));
    for(int i=1; i<N; i++){
        if(dq.back()!=str.at(i)){
            dq.push_back(str.at(i));
        }
    }
    if(!dq.empty() && dq.front()=='1'){
        dq.pop_front();
    }
    if(!dq.empty() && dq.back()=='1'){
        dq.pop_back();
    }
    ans=(dq.size()+1)/2*B;
    if(dq.size()!=0){
        ll t=0;
        while(dq.size()>1){
            t+=A;
            dq.pop_front();dq.pop_front();
        }
        t+=B;
        ans=min(ans, t);
    }
    cout<<ans;
    return 0;
}