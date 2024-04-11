//In the name of God
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int Maxn = 1e5 + 1e3;
int fdp[Maxn];
int sdp[Maxn];
int arr[Maxn];
vector<pair<int,int> > ans;
int main(){
    int n = 1e5;
    scanf("%d",&n);
    for(int i = 0; i < n;i++){
        scanf("%d",&arr[i]);
        if(i){
            fdp[i] += fdp[i-1] + 2-arr[i];
            sdp[i] += sdp[i-1] + arr[i]-1;
        }else{
            fdp[i] += 2-arr[i];
            sdp[i] += arr[i]-1;
        }
    }
    for(int t = 1; t <= n;t++){
        int s = 0;
        int now = -1;
        int first = 0;
        int second = 0;
        int winner = 0;
        while(1){
        //  cerr << t << " :() " << now << endl;
            if(now == n-1)
                break;
            if(now >= n)
                break;
            int faddp;
            int saddp;
            if(now != -1){
                faddp = lower_bound(fdp + now+1,fdp + n,fdp[now] + t) - fdp;
                saddp = lower_bound(sdp + now+1,sdp + n,sdp[now] + t) - sdp;
            }else{
                faddp = lower_bound(fdp + now+1,fdp + n,t) - fdp;
                saddp = lower_bound(sdp + now+1,sdp + n,t) - sdp;
            }
        //  cerr << faddp << " OOO " << saddp << endl;
            if(faddp > saddp)
                winner = 2;
            else
                winner = 1;
            if(winner == 1)
                first++;
            else
                second++;
            if(faddp == n && saddp == n){
                winner = -1;
                break;
            }
            now = min(faddp,saddp);
        }
        if(winner == -1)
            continue;
        if(first > second && winner == 1){
            ans.push_back(make_pair(first,t));
        }else if(second > first && winner == 2){
            ans.push_back(make_pair(second,t));
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size();i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}