#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, K;
vector<int> digs;

int main(){
    cin >> N >> K;
    while(N){
        digs.push_back(N%10);
        N/=10;
    }

    reverse(digs.begin(), digs.end());

    for(int i=0; i<digs.size(); i++){
        int nb = digs[i], nbi = i;
        for(int j=i+1; j<=i+K && j < digs.size(); j++)
            if(digs[j] > nb){
                nb = digs[j];
                nbi = j;
            }

        K -= nbi-i;
        for(int j=nbi; j>i; j--)
            digs[j] = digs[j-1];
        digs[i] = nb;
    }

    for(int i=0; i<digs.size(); i++)
        cout << digs[i];
    cout << endl;
    return 0;
}