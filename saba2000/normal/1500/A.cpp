#include<bits/stdc++.h>
using namespace std;
int M[5000009];
int a[200009], ind[200009];
int A[5000009],B[5000009];
main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int,int> > v;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        a[i] = v[i].first;
        ind[i] = v[i].second;
    }
    for(int i = 1; i < n; i+=2){
        int j = M[a[i] - a[i-1]];
        if(j){
            cout << "YES\n" << ind[i-1] <<" "<<ind[j] <<" "<<ind[i]<<" "<<ind[j-1] << endl;
            return 0;
        }
        M[a[i] - a[i-1]] = i;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            int d = a[i] - a[j];
            if(A[d] == 0){
                A[d] = i;
                B[d] = j;
                continue;
            }
            if(A[d] < j){
                //B[i] A[i] j i
                cout << "YES\n" << ind[B[d]] << " "<<ind[i]<<" "<<ind[A[d]]<<" "<<ind[j]<<endl;
                return 0;
            }

        }
    }
    cout << "NO"<<endl;
}