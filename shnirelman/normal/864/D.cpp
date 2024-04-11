#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    //ofstream fout("output.txt");
    //ifstream fin("input.txt");

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> cnt(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }

    int ind = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(ind < n && cnt[ind] != 0)
            ind++;

        if(ind >= n)break;

        if(cnt[a[i]] > 2 * n){
            a[i] = ind;
            cnt[ind] = 1;
            ans++;
        }
        else if(cnt[a[i]] > 1){
            if(a[i] > ind){
                cnt[a[i]]--;
                a[i] = ind;
                cnt[ind] = 1;
                ans++;
            }
            else cnt[a[i]] = 3 * n;
        }
    }

    cout << ans << endl;
    for(int i = 0; i < n; i++)cout << (a[i] + 1) << ' ';
}