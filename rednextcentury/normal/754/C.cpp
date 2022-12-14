#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define INF 1e18
#define OO 1e9
#define S second
#define F first

using namespace std;

vector<int> Ans;
const int N = 111;
int n ,m ,Memo[N][N];
map<int ,string> Msg;
map<int ,string> idUser;
map<string ,int> userId;


inline bool isAc( char c ){
    return (  c == '.' || c == ',' || c == '!'
           || c == '?' || c == ' ');
}

inline bool isValid( int msg ,int id ){
    string s = Msg[msg];
    for (auto &x:s) if (isAc(x)) x = ' ';
    stringstream message(s);
    string name  = idUser[id];
    string tmp;
    while(message>>tmp)
        if (tmp==name)return 0;
    return 1;
}

int match( int i ){
    if( i == m ) return 1;

    if( Ans[i] != 0 ){
        if( i && Ans[i] == Ans[i - 1] )
            return -1;
        if( Memo[i][ Ans[i]-1 ] != 0)
            return Memo[i][ Ans[i]-1 ];
        Memo[i][ Ans[i]-1 ] = match(i + 1);
        return Memo[i][ Ans[i]-1 ];
    }

    for(int name = 1 ; name <= n ; name ++){
        if( ( !i && isValid(i ,name) ) || /// BLA BLA BLA ...
            (  i && isValid(i ,name) && name != Ans[i-1] ) ){
            Ans[i] = name;
            if( Memo[i][ Ans[i]-1 ] == 0 )
                Memo[i][ Ans[i]-1 ] = match(i + 1);
            if( Memo[i][ Ans[i]-1 ] == 1 )
                return 1;
        }
    }

    Ans[i] = 0;
    return -1;
}

void Solve() {
    bool flag = true; {
        string tmp;
        userId.insert( MP("?", 0 ) );
        idUser.insert( MP( 0 ,"?") );

        cin >> n; cin.ignore();
        getline(cin ,tmp);
        stringstream names( tmp );
        for(int Cnt=1 ; names >> tmp ; Cnt++){
                userId[ tmp ] = Cnt;
                idUser[ Cnt ] = tmp;
                if( isdigit( tmp[0] ) )
                    flag = false;
        }
    }

    cin >> m; cin.ignore();
    Ans.assign(m ,0);
    for(int i=0 ; i<m ;i++){
            unsigned int id ,sz ;
            string tmp ,user ,msg = "";
            getline(cin ,tmp);
            stringstream inputMsg(tmp);

            inputMsg >> tmp;
            for(sz=0 ; sz<tmp.size() ; sz++)
                if( tmp[sz] == ':' )
                    break;

            user = tmp.substr(0 ,sz);
            id   = userId[ user ];
            tmp  = tmp.substr( sz + 1 );
            msg  = msg + tmp;
            while( inputMsg >> tmp )
                msg = msg + " " + tmp;
            Ans[i] = id;
            Msg[i] = msg;
    }

    if( flag ){ /// --- \BRUTEFORCE DP SOLUTION --- ///
            for(int i=0 ; i<m ; i++)
                for(int j=0 ; j<n ; j++)
                    Memo[i][j] = 0;

            if( match(0) == -1 )
                    cout << "Impossible" << endl;
            else
                for(int i=0 ; i<m ; i++)
                    cout << idUser[ Ans[i] ] << ':' << Msg[i] << endl;

    } else { /// --- \ERROR IN THE MESSAGES OR USERS --- ///
            cout << "Impossible" << endl;
    }

    userId.clear();
    idUser.clear();
    Msg.clear();
    Ans.clear();
    return;
}

int main()
{
    int Tc; cin >> Tc;
    while( Tc-- ) Solve();
    return 0;
}