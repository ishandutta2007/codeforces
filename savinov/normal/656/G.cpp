/*^_^*/
#include <iostream>
#include <vector>
int main(){int a,kitten,c;std::cin>>a>>kitten>>c;std::string x[a];for(auto &t:x)std::cin>>t;int res=0;for(int j=0;j<kitten;++j){int cnt=0;for(auto v:x)if(v[j]=='Y')cnt++;res+=cnt>=c;}std::cout<<res<<"\n";}