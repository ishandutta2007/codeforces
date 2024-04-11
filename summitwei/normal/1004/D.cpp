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
#define MOD 998244353
#define EPSILON 0.00001

ll mod(int a, int b){
    return ((a % b) + b) % b;
}

int calcPts(int length, int width, pii zero, int dist){
    //our edges WILL doublecount the corners so check those separately
    //reminder: square is zero-based, first is associated with len and second with width
    //THIS NEEDS TO BE A CONSTANT FUNCTION

    int totalPts = 0;

    int firstPt;
    int lastPt;

    //upper left edge
    if(zero.second >= dist){
        firstPt = zero.first;
    } else{
        firstPt = zero.first - (dist - zero.second);
        //make sure to check that firstpt is nonneg
    }
    if(zero.first >= dist){
        lastPt = zero.first - dist;
    } else{
        lastPt = 0;
    }
    if(firstPt >= 0  && firstPt >= lastPt){
        totalPts += (firstPt - lastPt + 1);
        //cout << "number in upper left edge is " << firstPt - lastPt + 1 << "\n";
    }

    //lower right edge
    if(zero.second + dist <= width - 1){
        firstPt = zero.first;
    } else{
        firstPt = zero.first + (dist + zero.second - (width-1));
    }
    if(zero.first + dist <= length - 1){
        lastPt = zero.first + dist;
    } else{
        lastPt = length - 1;
    }
    if(firstPt <= length-1 && firstPt <= lastPt){
        totalPts += (lastPt - firstPt + 1);
        //cout << "number in lower right edge is " << lastPt - firstPt + 1 << "\n";
        //cout << "first point is " << firstPt << " and last pt is " << lastPt << "\n";
    }

    //lower left edge
    if(zero.second >= dist){
        firstPt = zero.first;
    } else{
        firstPt = zero.first + (dist - zero.second);
    }
    if(zero.first + dist <= length - 1){
        lastPt = zero.first + dist;
    } else{
        lastPt = length - 1;
    }
    if(firstPt >= 0  && firstPt <= lastPt){
        totalPts += (lastPt - firstPt + 1);
        //cout << "number in lower left edge is " << lastPt - firstPt + 1 << "\n";
        //cout << "first point is " << firstPt << " and last pt is " << lastPt << "\n";
    }

    //upper right edge
    if(zero.second + dist <= width - 1){
        firstPt = zero.first;
    } else{
        firstPt = zero.first - (dist + zero.second - (width-1));
    }
    if(zero.first >= dist){
        lastPt = zero.first - dist;
    } else{
        lastPt = 0;
    }
    if(firstPt <= length-1 && firstPt >= lastPt){
        totalPts += (firstPt - lastPt + 1);
        //cout << "number in upper right edge is " << firstPt - lastPt + 1 << "\n";
        //cout << "first point is " << firstPt << " and last pt is " << lastPt << "\n";
    }

    if(zero.first >= dist) totalPts--;
    if(zero.second >= dist) totalPts--;
    if(zero.first + dist <= length-1) totalPts--;
    if(zero.second + dist <= width-1) totalPts--;

    return totalPts;
}

int main(){
    //loop through all possibilities for the factors of t.
    //then, for each of these, assume the upper right guy is the max number
    //and then figure out every possibility.
    //if we can check to see if a possibility works in o(maxnum) we are good.
    //this should be possible?

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    vi dists(t);
    for(int i=0; i<t; i++){
        cin >> dists[i];
    }

    if(t == 1){
        cout << "1 1\n1 1";
        return 0;
    }

    sort(dists.begin(), dists.end());

    if(dists[0] != 0 || dists[1] == 0){
        cout << -1;
        return 0;
    }

    int maxDist = dists[t-1];

    vi amtOfDists(maxDist+1);
    for(int i=0; i<t; i++){
        amtOfDists[dists[i]]++;
    }

    for(int i=1; i<=(sqrt(t)+EPSILON); i++){
        if(t % i != 0) continue;

        int width = t / i;
        if(i + width < maxDist + 2) continue;

        for(int j=0; j<=maxDist; j++){
            if(j >= i || (maxDist - j) >= width) continue;

            int works = true;
            for(int k=1; k<=maxDist; k++){
                if(calcPts(i, width, make_pair(j, maxDist-j), k) != amtOfDists[k]){
                    works = false;
                    break;
                }
            }
            
            if(works){
                cout << i << " " << width << "\n" << i-j << " " << width - (maxDist - j);
                return 0;
            }
        }
    }
    
    cout << -1;

    /*int width, length, zeroX, zeroY, dist;
    cin >> length >> width >> zeroX >> zeroY >> dist;
    pii zeroLoc = make_pair(zeroX, zeroY);
    cout << calcPts(length, width, zeroLoc, dist);*/

    return 0;
}