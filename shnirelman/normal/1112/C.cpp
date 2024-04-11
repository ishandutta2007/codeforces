#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, s, m;
    cin >> m >> k >> n >> s;

    vector<int> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
        a[i]--;
    }

    vector<int> cnt(5 * 100013, 0);
    vector<int> c(5 * 100013, 0);
    for(int i = 0; i < s; i++){
        int b1;
        cin >> b1;
        cnt[b1 - 1]++;
        c[b1 - 1]++;
    }

    int b = 0;
    for(int i = 0; i < m - k * (n - 1); i++){
        cnt[a[i]]--;
    }

    for(int i = 0; i < cnt.size(); i++){
        if(cnt[i] > 0)b++;
    }
//cout << "dsh";
vector<int> an(5e5, -1);
int ind = 0;
    int len = m - (n - 1) * k;
    for(int i = 0; i < m; i += k){
            //cout << i << ' ' << b << endl;
        //for(int j =0; j < 10; j++)cout << cnt[j] << ' ';
        //cout << endl;
        //cout << i;
        if(b == 0){

            int c1 = 0;
            for(int j = i; j < min(i + len, m); j++){
                    //cout << j << ' ' << a[j] << ' ' << c[a[j]] << endl;
                if(c[a[j]] <= 0 && c1 < len - k){
                    an[ind] = j + 1;
                    ind++;
                    //an.push_back(j);
                    c1++;
                }
                else c[a[j]]--;//cout << j << ' ' << a[j] << ' ' << c[a[j]] << endl;
            }
            cout << ind << endl;
            for(i = 0; i < ind; i++) cout << an[i] << ' ';
            return 0;
        }
//cout << i;
        for(int j = i; j < min(i + k, m); j++){
            cnt[a[j]]++;
            if(cnt[a[j]] == 1)b++;
        }//cout << i;
        for(int j = i + len; j < min(i + len + k, m); j++){
            cnt[a[j]]--;//cout << j << ' ';
            if(cnt[a[j]] == 0)b--;
            //cout << j << ' ';
        }
//cout << i;
    }
    cout << -1;
}