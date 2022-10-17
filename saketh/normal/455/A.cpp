#include <iostream>
#include <map>
using namespace std;

int N, M, v[100005];
map<long long, int> ct;
pair<long long, int> val[100005];
long long ans[100005][2];

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> v[i];
        ct[v[i]]++;
    }

    for(map<long long, int>::iterator it = ct.begin(); it!=ct.end(); it++)
        val[M++] = *it;

    ans[0][0] = ans[0][1] = 0;

    for(int i=0; i<M; i++){
        ans[i+1][0] = max(ans[i][0], ans[i][1]);
        ans[i+1][1] = ans[i][0] + val[i].first * val[i].second;
        if(i==0 || ((val[i-1].first+1) != val[i].first))
            ans[i+1][1] = max(ans[i+1][1],
                ans[i][1] + val[i].first * val[i].second);
    }

    cout << max(ans[M][0], ans[M][1]) << endl;
    return 0;
}