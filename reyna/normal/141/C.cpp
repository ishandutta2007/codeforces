//In the name of God
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 3050;
pair<int,string> srt[Maxn]; 
pair<string,int> arr[Maxn];
int fst = 0;
int L[Maxn];
int R[Maxn];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> srt[i].second >> srt[i].first;
    }
    sort(srt,srt+n);
    L[0] = -1;
    R[0] = -1;
    for(int i = 0; i < n;i++){
        int num = srt[i].first;
        if(num > i){
            cout << -1 << endl;
            return 0;
        }
        if(!i){
            arr[i].first = srt[i].second;
            arr[i].second = n;
            continue;
        }
        int t = fst;
        int last = 0;
        for(int j = 0; j < num;j++)
            last = t,t = R[t];
        if(t == fst){
            L[fst] = i;
            R[i] = fst;
            L[i] = -1;
            fst = i;
            arr[i].first = srt[i].second;
            arr[i].second = n - i; 
        }else{
            L[i] = last;
            R[i] = t;
            if(last + 1)
                R[last] = i;
            if(t + 1)
                L[t] = i;
            arr[i].first = srt[i].second;
            arr[i].second = n - i; 
        }
    }
    while(fst + 1){
        cout << arr[fst].first << ' ' << arr[fst].second << endl;
        fst = R[fst];
    }
    return 0;
}