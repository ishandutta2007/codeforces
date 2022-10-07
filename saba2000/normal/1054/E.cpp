#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
int s[309][309];
vector<pair<pair<int,int>, pair<int,int> > > ans1, ans2,ans3,ans4;
main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1;i  <= n; i++){
        for(int j = 1; j <= m; j++){
            string s;
            cin >> s;
            for(int k = s.size()-1; k >= 0; k--){
                 if(s[k] == '0') {
                     if(i == 1 && j == 1) {
                         ans1.push_back({{1,1},{2,1}}); 
                         ans3.push_back({{2,1},{1,1}});
                         continue;
                     }
                    if(j > 1) {ans1.push_back({{i,j},{i,1}}); 
                    if(i > 1) ans3.push_back({{i,1},{1,1}});}
                    else if(i > 1) ans1.push_back({{i,1},{1,1}});
                }
                else{
                      if(i == 1 && j == 2) {
                         ans1.push_back({{1,2},{2,2}}); 
                         ans3.push_back({{2,2},{1,2}});
                         continue;
                     }
                    if(j != 2) {ans1.push_back({{i,j},{i,2}});
                    if(i != 1) ans3.push_back({{i,2},{1,2}});}
                    else if(i != 1) ans1.push_back({{i,2},{1,2}});
                }
            }
        }
    }
    //   dc
      for(int i = 1;i  <= n; i++){
        for(int j = 1; j <= m; j++){
            string s;
            cin >> s;
            for(int k = 0; k < s.size(); k++){
            if(s[k] == '0') {
                     if(i == 1 && j == 1) {
                         ans2.push_back({{1,1},{2,1}}); 
                         ans4.push_back({{2,1},{1,1}});
                         continue;
                     }
                    if(j > 1) {ans2.push_back({{i,j},{i,1}}); 
                    if(i > 1) ans4.push_back({{i,1},{1,1}});}
                    else if(i > 1) ans2.push_back({{i,1},{1,1}});
                }
                else{
                      if(i == 1 && j == 2) {
                         ans2.push_back({{1,2},{2,2}}); 
                         ans4.push_back({{2,2},{1,2}});
                         continue;
                     }
                    if(j != 2) {ans2.push_back({{i,j},{i,2}});
                    if(i != 1) ans4.push_back({{i,2},{1,2}});}
                    else if(i != 1) ans2.push_back({{i,2},{1,2}});
                }
            }
        }
    }
    for(int i = 0; i < ans3.size(); i++)
        ans1.push_back(ans3[i]);
      for(int i = 0; i < ans4.size(); i++)
        ans2.push_back(ans4[i]);
    reverse(ans2.begin(), ans2.end());
    cout<<ans1.size() + ans2.size()<<endl;
    for(int i = 0; i < ans1.size(); i++){
       printf("%d %d %d %d\n",ans1[i].F.F,ans1[i].F.S,ans1[i].S.F,ans1[i].S.S);
    }
    for(int i = 0; i < ans2.size(); i++){
        printf("%d %d %d %d\n",ans2[i].S.F,ans2[i].S.S,ans2[i].F.F,ans2[i].F.S);
    }
}