#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
typedef vector<vector<long long>> vvll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<int, long>> vpil;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef long long ll;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<vector<bool>> vvb;
typedef set<int> si;
#define INF 100000000
#define MOD 257

int mod(int a, int b){
    return ((a % b) + b) % b;
}

int main(){
    int n;
    cin >> n;
    
    vi conns(n,0);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        conns[a-1]++;
        conns[b-1]++;
    }

    int numOver = 0;
    int numWithMore = -1;
    for(int i=0; i<n; i++){
        if(conns[i] > 2){
            numOver++;
            numWithMore = i;
        }
    }

    if(numOver >= 2){
        cout << "No";
        return 0;
    }

    if(numOver == 0){
        cout << "Yes\n1\n";
        vi nums;
        for(int i=0; i<n; i++){
            if(conns[i]==1){
                nums.push_back(i+1);
            }
        }

        cout << nums[0] << " " << nums[1];
    } else{
        vi nums;
        for(int i=0; i<n; i++){
            if(conns[i]==1){
                nums.push_back(i+1);
            }
        }

        cout << "Yes\n" << nums.size() << "\n";
        
        for(int i=0; i<nums.size(); i++){
            cout << numWithMore+1 << " " << nums[i] << "\n";
        }
    }


    return 0;
}