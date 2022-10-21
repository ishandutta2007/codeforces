#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> f(100050);
vector<int> prime;
map<int, int> M;
bool on[100050];

void set_prime(){
    for(int i = 2; i <= 100000; i++){
        if(f[i].size() == 0){
            prime.push_back(i);
            for(int j = i; j <= 100000; j+=i){
                f[j].push_back(i);
            }
        }
    }
}

int conflict(int t){
    for(int i = 0; i < f[t].size(); i++){
        if(M.count(f[t][i])) return M[f[t][i]];
    }
    return -1;
}

int main(){
    fill(on, on+100050, false);
    set_prime();
    int n, m, k;
    char c;
    cin >> n >> m;
    while(m--){
        getchar();
        scanf("%c%d", &c, &k);

        if(c == '-'){
            if(!on[k]) printf("Already off\n");
            else {
                for(int i = 0; i < f[k].size(); i++){
                    M.erase(f[k][i]);
                }
                printf("Success\n"), on[k] = false;
            }
        }
        else{
            if(on[k]) printf("Already on\n");
            else{
                int con = conflict(k);
                if(con >= 0) printf("Conflict with %d\n", con);
                else{
                    on[k] = true;
                    for(int i = 0; i < f[k].size(); i++){
                        M[f[k][i]] = k;
                    }
                    printf("Success\n");
                }
            }
        }
    }

}