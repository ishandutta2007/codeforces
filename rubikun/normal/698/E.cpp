#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=105,INF=1<<30;

vector<int> monlen={31,28,31,30,31,30,31,31,30,31,30,31};

ll f(ll y,ll tuki,ll dd,ll youbi,ll hh,ll mm,ll ss){
    ll res=0;
    for(ll i=1970;i<y;i++){
        if((i%400==0)||(i%100!=0&&i%4==0)){
            res+=366*24*60*60;
        }else{
            res+=365*24*60*60;
        }
    }
    
    for(int i=0;i<tuki;i++){
        ll z=monlen[i];
        if((y%400==0)||(y%100!=0&&y%4==0)){
            if(i==1) z++;
        }
        res+=z*24*60*60;
    }
    
    res+=dd*24*60*60;
    
    res+=hh*60*60;
    
    res+=mm*60;
    
    res+=ss;
    
    return res;
}

void upd(ll &y,ll &tuki,ll &dd,ll &youbi,ll &hh,ll &mm,ll &ss){
    mm+=ss/60;
    ss%=60;
    hh+=mm/60;
    mm%=60;
    ll x=hh/24;
    youbi=(youbi+x)%7;
    dd+=x;
    hh%=24;
    for(ll i=tuki;;i++){
        ll z=monlen[i%12];
        if((y%400==0)||(y%100!=0&&y%4==0)){
            if(i%12==1) z++;
        }
        if(dd>=z){
            dd-=z;
            tuki++;
            if(tuki==12){
                y++;
                tuki=0;
            }
        }else{
            break;
        }
    }
}

ll s,m,h,day,date,month;

bool check(ll &y,ll &tuki,ll &dd,ll &youbi,ll &hh,ll &mm,ll &ss){
    upd(y,tuki,dd,youbi,hh,mm,ss);
    
    if(month!=-1){
        if(month!=tuki) return false;
    }
    if(h!=-1){
        if(hh!=h) return false;
    }
    if(m!=-1){
        if(mm!=m) return false;
    }
    if(s!=-1){
        if(ss!=s) return false;
    }
    if(date==-1&&day==-1){
        
    }else if(date==-1){
        if(day!=youbi) return false;
    }else if(day==-1){
        if(date!=dd) return false;
    }else{
        if((date!=dd)&&(day!=youbi)) return false;
    }
    
    return true;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>s>>m>>h>>day>>date>>month;
    day--;date--;month--;
    if(day<0) day=-1;
    if(date<0) date=-1;
    if(month<0) month=-1;
    
    int Q;cin>>Q;
    while(Q--){
        ll x;cin>>x;x++;
        ll sx=x;
        ll y=1970,tuki,dd,youbi,hh,mm,ss;
        youbi=(x/(24*60*60)+3)%7;
        while(1){
            if(y%400==0||(y%100!=0&&y%4==0)){
                if(x>=366*24*60*60){
                    y++;
                    x-=366*24*60*60;
                }else{
                    for(int i=0;i<12;i++){
                        ll z=monlen[i]+(i==1);
                        if(x>=z*24*60*60){
                            x-=z*24*60*60;
                        }else{
                            tuki=i;
                            dd=x/(24*60*60);
                            x%=(24*60*60);
                            hh=x/(60*60);
                            x%=(60*60);
                            mm=x/60;
                            ss=x%60;
                            break;
                        }
                    }
                    break;
                }
            }else{
                if(x>=365*24*60*60){
                    y++;
                    x-=365*24*60*60;
                }else{
                    for(int i=0;i<12;i++){
                        ll z=monlen[i];
                        if(x>=z*24*60*60){
                            x-=z*24*60*60;
                        }else{
                            tuki=i;
                            dd=x/(24*60*60);
                            x%=(24*60*60);
                            hh=x/(60*60);
                            x%=(60*60);
                            mm=x/60;
                            ss=x%60;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        
        //cout<<y<<" "<<tuki<<" "<<dd<<" "<<youbi<<" "<<hh<<" "<<mm<<" "<<ss<<endl;
        //0-indexed
        
        if(check(y,tuki,dd,youbi,hh,mm,ss)){
            cout<<f(y,tuki,dd,youbi,hh,mm,ss)<<"\n";
            continue;
        }
        
        if(s==-1){
            if(ss){
                ss+=(60-ss);
                upd(y,tuki,dd,youbi,hh,mm,ss);
            }
        }else{
            if(ss<=s){
                ss+=(s-ss);
                upd(y,tuki,dd,youbi,hh,mm,ss);
            }else{
                ss+=(60+s-ss);
                upd(y,tuki,dd,youbi,hh,mm,ss);
            }
        }
        
        //cout<<y<<" "<<tuki<<" "<<dd<<" "<<youbi<<" "<<hh<<" "<<mm<<" "<<ss<<endl;
        
        if(check(y,tuki,dd,youbi,hh,mm,ss)){
            cout<<f(y,tuki,dd,youbi,hh,mm,ss)<<"\n";
            continue;
        }
        
        if(m==-1){
            if(mm){
                mm+=(60-mm);
                upd(y,tuki,dd,youbi,hh,mm,ss);
            }
        }else{
            if(mm<=m){
                mm+=(m-mm);
                upd(y,tuki,dd,youbi,hh,mm,ss);
            }else{
                mm+=(60+m-mm);
                upd(y,tuki,dd,youbi,hh,mm,ss);
            }
        }
        
        //cout<<y<<" "<<tuki<<" "<<dd<<" "<<youbi<<" "<<hh<<" "<<mm<<" "<<ss<<endl;
        if(check(y,tuki,dd,youbi,hh,mm,ss)){
            cout<<f(y,tuki,dd,youbi,hh,mm,ss)<<"\n";
            continue;
        }
        
        if(h==-1){
            if(hh){
                hh+=(24-hh);
                upd(y,tuki,dd,youbi,hh,mm,ss);
            }
        }else{
            if(hh<=h){
                hh+=(h-hh);
                upd(y,tuki,dd,youbi,hh,mm,ss);
            }else{
                hh+=(24+h-hh);
                upd(y,tuki,dd,youbi,hh,mm,ss);
            }
        }
        
        //cout<<y<<" "<<tuki<<" "<<dd<<" "<<youbi<<" "<<hh<<" "<<mm<<" "<<ss<<endl;
        
        if(check(y,tuki,dd,youbi,hh,mm,ss)){
            cout<<f(y,tuki,dd,youbi,hh,mm,ss)<<"\n";
            continue;
        }
        
        while(1){
            hh+=24;
            if(check(y,tuki,dd,youbi,hh,mm,ss)){
                cout<<f(y,tuki,dd,youbi,hh,mm,ss)<<"\n";
                break;
            }
        }
        
        //cout<<sx<<" "<<f(y,tuki,dd,youbi,hh,mm,ss)<<endl;
    }
}