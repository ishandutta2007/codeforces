#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 2000000000000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 200005

pair<bool, ll> numbers[MAX_N];
//compress ones
//true = seq of ones, false = normal number

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int totOnes = 0;

    int currOn = 0;
    int ones = 0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;

        if(a == 1){
            ones++;
            totOnes++;
        } else if(ones > 0){
            numbers[currOn] = {true, ones};
            currOn++;
            numbers[currOn] = {false, a};
            currOn++;
            ones = 0;
        } else{
            numbers[currOn] = {false, a};
            currOn++;
        }
    }

    if(ones != 0){
        numbers[currOn] = {true, ones};
        currOn++;
    }

    int cnt = 0;

    if(k == 1){
        cnt += totOnes; //only when k=1 will something with just ones work
    }

    //cout << "total size is " << currOn << "\n";

    /*for(int i=0; i<currOn; i++){
        if(numbers[i].first){
            cout << "1:" << numbers[i].second << " ";
        } else{
            cout << numbers[i].second << " ";
        }
    }
    cout << "\n";*/

    for(int i=0; i<currOn; i++){
        if(numbers[i].first) continue;

        //cout << "i is " << i << "\n";
        
        ll optionalOnes = 0;
        if(i != 0 && numbers[i-1].first){
            optionalOnes = numbers[i-1].second;
        }


        ll prod = 1;
        ll sum = 0;

        int curr = 0;
        int on = i;
        while(curr <= 60 && on < currOn){
            if(numbers[on].first){
                sum += numbers[on].second;
            } else{
                ll other = numbers[on].second;
                if(INF / prod < other){
                    break; //product over 2*10^18 --> this is never working
                }

                prod *= other;
                sum += other;
                curr++;

                //cout << i << ", " << j << " has prod of " << prod << "\n";

                if(prod % k != 0){
                    on++;
                    continue;
                }

                ll toGet = prod/k;
                //cout << "for " << i << " " << j << ", toGet is " << toGet << "\n";
                ll extraOnes = optionalOnes;
                if(on < currOn-1 && numbers[on+1].first){
                    extraOnes += numbers[on+1].second;
                }
                if(toGet >= sum && toGet <= sum+extraOnes){
                    //cnt++;
                    ll outerOnes = toGet-sum;
                    
                    ll asdf = numbers[on+1].first ? numbers[on+1].second : 0;
                    ll leftMin = max(0LL, outerOnes-asdf);
                    ll leftMax = min(optionalOnes, outerOnes);

                    cnt += (leftMax-leftMin+1);

                    //cout << i << " " << j << " contributes " << leftMax-leftMin+1 << " solutions!\n";
                }
            }

            on++;
        }
    }

    cout << cnt << "\n";


    return 0;
}