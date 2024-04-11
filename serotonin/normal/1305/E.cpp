#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5005;

void chk(vector <int> ans)
{
    int tot=0;
    for(int i=0; i<ans.size(); i++) {
        for(int j=i+1; j<ans.size(); j++) {
            for(int k=j+1; k<ans.size(); k++) {
                if(ans[i] + ans[j] == ans[k]) tot++;
            }
        }
    }
    cout << tot << endl;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector <int> ans;
    for(int i=1; ; i++) {
        int now = 0;
        for(int j=i; j<i+n; j++) {
            int b = i+n-1-j;
            if(b>j) now += b-j;
        }
        int no = 0;
        for(int j=i; j<i+n-1; j++) {
            int b = i+n-1-1-j;
            if(b>j) no += b-j;
        }
//        printf("%d %d %d\n", now, no, now-no);

        if(now==m) {
            for(int j=i; j<i+n; j++) ans.push_back(j);
            break;
        }

        if(now>m && no<=m) {
            int b = m - no;
            for(int j=i; j<i+n-1; j++) ans.push_back(j);
            int x = i+n-2;
            int y = x - (2*b-1);
            ans.push_back(x+y);
            break;
        }

        if(i==1 && now<m) {
            puts("-1");
            exit(0);
        }
    }


    for(int v : ans) printf("%d ", v);

//    chk(ans);
}