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
    int N;
    cin >> N;

    vpii first(3);
    vpii second(3); //for things with more than one character
    vi firstOne(3);
    vi secondOne(3); //these are for one character long things

    for(int i=0; i<N; i++){
        string a;
        cin >> a;

        if(a.length() == 1){
            if(a == "S"){
                firstOne[0]++;
            } else if(a == "M"){
                firstOne[1]++;
            } else{
                firstOne[2]++;
            }
        } else{
            if(a[a.length()-1] == 'S'){
                first[a.length()-2].first++;
            } else{
                first[a.length()-2].second++;
            }
        }
    }

    for(int i=0; i<N; i++){
        string a;
        cin >> a;

        if(a.length() == 1){
            if(a == "S"){
                secondOne[0]++;
            } else if(a == "M"){
                secondOne[1]++;
            } else{
                secondOne[2]++;
            }
        } else{
            if(a[a.length()-1] == 'S'){
                second[a.length()-2].first++;
            } else{
                second[a.length()-2].second++;
            }
        }
    }

    int numChanges = 0;
    for(int i=0; i<3; i++){
        int x = first[i].first-second[i].first;
        if(x < 0) x = -x;
        numChanges += x;
    }

    int maxNum = 0;
    for(int i=0; i<3; i++){
        int x = firstOne[i]-secondOne[i];
        if(x < 0) x = -x;
        maxNum = max(maxNum, x);
    }
    numChanges += maxNum;

    cout << numChanges;
    return 0;
}