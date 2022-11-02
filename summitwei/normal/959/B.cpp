#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
#define MODBASE 1000000007
#define INF 1000000000

struct word{
    string value;
    ll cost;
    int group;
};

int main(){
    int n, k, m;
    cin >> n >> k >> m;

    map<string, word> words;
    vector<string> arrOfStrings(n);
    for(int i=0; i<n; i++){
        cin >> arrOfStrings[i];
        word newWord;
        newWord.value = arrOfStrings[i];
        words.insert(make_pair(arrOfStrings[i], newWord));
    }
    for(int i=0; i<n; i++){
        ll thisCost;
        cin >> thisCost;
        words[arrOfStrings[i]].cost = thisCost;
    }

    vll minCost(k);
    for(int i=0; i<k; i++){
        ll currMin = INF;
        int numInGroup;
        cin >> numInGroup;
        for(int j=0; j<numInGroup; j++){
            int currWord;
            cin >> currWord;
            words[arrOfStrings[currWord-1]].group = i;
            currMin = min(currMin, words[arrOfStrings[currWord-1]].cost);
        }
        minCost[i] = currMin;
    }

    ll totalAmt = 0;
    for(int i=0; i<m; i++){
        string toCheck;
        cin >> toCheck;
        totalAmt += minCost[words[toCheck].group];
    }

    cout << totalAmt;

    return 0;
}