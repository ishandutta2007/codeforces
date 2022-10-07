#include<bits/stdc++.h>
using namespace std;
main(){
    long long n;
    cin >> n;
    vector<pair<long long,long long> > v[59];
    for(long long i= 0 ;i < 50; i++){
        for (long long j =0 ; j < 50; j++){
            if(i+j > n) continue;
            long long N = n - i - j;
            long long X = 5*i+10*j;
            v[(N+X)%49].push_back({(N+X),50*N+X});

        }
    }
    long long ans=  0;
    for(long long i = 0; i < 49; i++){
        sort(v[i].begin(),v[i].end());
        long long M = -1;
        for(long long j= 0 ; j < v[i].size(); j++){
            //cout << i << " "<<j<<" "<<v[i][j].first <<" "<<v[i][j].second<<endl;
            if(v[i][j].first > M) {
                ans += ((v[i][j].second - v[i][j].first)/49+1);
                M = v[i][j].second;
            } else
            if(v[i][j].second < M) continue;
            else ans += ((v[i][j].second - M))/49, M = v[i][j].second;
        }
    }
    cout << ans << endl;
}