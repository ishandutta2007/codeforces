#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
typedef vector<vector<long long>> vvll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<int, long long>> vpil;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef long long ll;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<vector<bool>> vvb;
typedef set<int> si;
typedef vector<vector<set<int>>> vvsi;
typedef vector<vector<set<pair<long long, long long>>>> vvspll;
typedef pair<long long, long long> pll;
typedef pair<long long, pair<long long, long long>> trip;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001

ll mod(int a, int b){
    return ((a % b) + b) % b;
}

int main(){
    int n;
    cin >> n;

    vector<pair<ll, bool>> points(2*n);
    for(int i=0; i<n; i++){
        ll x, y;
        cin >> x >> y;
        points[2*i] = make_pair(x, false);
        points[2*i+1] = make_pair(y, true);
    }
    sort(points.begin(), points.end());

    vector<ll> numPts(n+1, 0);

    if(points[0].first != points[1].first){
        numPts[1]++;
    }
    int currNumSegs = 1;
    for(int i=1; i<2*n-1; i++){ //we want to deal with last separately, REMINDER
        //for multiple things that are the same, we process right after all falses and before all trues
        //also, do not process things when we reach them
        if(points[i].first != points[i-1].first && points[i].first != points[i+1].first){
            ll dist = points[i].first - points[i-1].first-1;
            numPts[currNumSegs] += dist;

            if(points[i].second){
                numPts[currNumSegs]++;
            } else{
                numPts[currNumSegs+1]++;
            }
            //cout << dist << " length of " << currNumSegs << "\n";
        } else if(points[i].first == points[i-1].first && points[i].first != points[i+1].first){
            //ONLY PROCESS THIS ONE POINT, AND ONLY IF THIS IS A BETTER PLACE TO PROCESS THAN THE PREVIOUS ONE
            //if(points[i-1].second) continue; //continue here because this pt has already been processed.
            if(!points[i-1].second){
                if(points[i].second){
                    numPts[currNumSegs]++;
                } else{
                    numPts[currNumSegs+1]++;
                }
            }
            //cout << "one point of " << currNumSegs << "\n";
        } else if(points[i].first != points[i-1].first && points[i].first == points[i+1].first){
            ll dist = points[i].first - points[i-1].first-1;
            numPts[currNumSegs] += dist;
            //cout << dist << " length of " << currNumSegs << "\n";

            if(points[i].second){
                numPts[currNumSegs]++;
                //cout << "one point of " << currNumSegs << " too\n";
            }
        } else{
            //if(points[i-1].second) continue;
            //if(!points[i].second) continue;

            if(!points[i-1].second && points[i].second){
                numPts[currNumSegs]++;
            }
            //cout << "one point of " << currNumSegs << "\n";
        }

        if(points[i].second){
            currNumSegs--;
        } else{
            currNumSegs++;
        }
    }
    if(points[2*n-1].first == points[2*n-2].first){
        if(!points[2*n-2].second) numPts[1]++;
    } else{
        ll finalDist = points[2*n-1].first - points[2*n-2].first;
        numPts[1] += finalDist;
    }

    for(int i=1; i<=n; i++){
        cout << numPts[i] << " ";
    }
    return 0;
}