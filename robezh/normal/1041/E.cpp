#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
int a,b;
int num[N];
bool exi[N];

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        if((a != n && b != n) || (a == n && b == n)) return !printf("NO");
        num[i] = (a != n ? a : b);
        num[i]--;
    }
    sort(num, num+n-1);
    for(int i = 0; i < n-1; i++){
        if(num[i] < i) return !printf("NO");
    }
    vector<int> res;

    int pv = -1;
    for(int i = 0; i < n-1; i++){
        if((pv >= num[i])){
            int j;
            for(j = 0; j < n-1; j++){
                if(!exi[j]){
                    break;
                }
            }
            res.push_back(j);
            exi[j] = true;
        }
        else{
            res.push_back(num[i]);
            exi[num[i]] = true;
            pv = max(pv, num[i]);
        }
    }
    res.push_back(n-1);
    cout << "YES" << endl;
    for(int i = 0; i < n-1; i++){
        cout << res[i]+1 << " " << res[i+1]+1 << endl;
    }
}