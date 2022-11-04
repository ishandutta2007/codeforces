//#include <iostream>
//#include <vector>
//#include <set>
//#include <string>

//using namespace std;

//#define mods_size 2
//#define MAX_N 10000

//int mods[] = {57122617, 68955899};

//struct hash_struct
//{
//    int hashs[mods_size];

//    hash_struct()
//    {
//        for (int i = 0; i < mods_size; ++i)
//            hashs[i] = 0;
//    }

//    hash_struct(int arr[])
//    {
//        for (int i = 0; i < mods_size; ++i)
//            hashs[i] = arr[i];
//    }

//    bool operator<(hash_struct &s)
//    {
//        for (int i = 0; i < mods_size; ++i)
//            if (hashs[i] != s.hashs[i])
//                return hashs[i] < s.hashs[i];
//        return false;
//    }

//    hash_struct operator=(hash_struct s)
//    {
//        for (int i = 0; i < mods_size; ++i)
//            hashs[i] = s.hashs[i];
//        return *this;
//    }

//    bool operator==(hash_struct &s)
//    {
//        for (int i = 0; i < mods_size; ++i)
//            if (hashs[i] != s.hashs[i])
//                return false;
//        return true;
//    }
//};

//hash_struct operator*(hash_struct &s1, int s)
//{
//    int res_hash[mods_size];
//    for (int i = 0; i < mods_size; ++i)
//    {
//        long long l = (long long)s1.hashs[i] * (long long)s;
//        res_hash[i] = l % mods[i];
//    }
//    return hash_struct(res_hash);
//}

//hash_struct operator+(hash_struct &s1, int s)
//{
//    int res_hash[mods_size];
//    for (int i = 0; i < mods_size; ++i)
//    {
//        res_hash[i] = s1.hashs[i] + s;
//        res_hash[i] %= mods[i];
//    }
//    return hash_struct(res_hash);
//}

//hash_struct operator+(hash_struct &s1, hash_struct &s)
//{
//    int res_hash[mods_size];
//    for (int i = 0; i < mods_size; ++i)
//    {
//        res_hash[i] = s1.hashs[i] + s.hashs[i];
//        res_hash[i] %= mods[i];
//    }
//    return hash_struct(res_hash);
//}

//hash_struct to_hash_struct(string &s)
//{
//    hash_struct h;
//    for (auto &x : s)
//    {
//        h = h * 10;
//        h = h + (x - '0');
//    }
//    return h;
//}

//set<hash_struct> st;

//void init()
//{
//    hash_struct a, b, c;
//    a = a + 1;
//    b = b + 1;
//    c = c + 1;
//    st.insert(a);
//    for (int i = 2; i < MAX_N; ++i)
//    {
//        c = a + b;
//        a = b;
//        b = c;
//        st.insert(c);
//    }
//}

//int main()
//{
//    int n;
//    cin >> n;
//    string s;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> s;
//        if (st.count(to_hash_struct(s)))
//            cout << "YES\n";
//        else
//            cout << "NO\n";
//    }
//}
#include <iostream>

using namespace std;

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int m, d;
    cin >> m >> d;
    --m;
    int amnt = days[m] - 8 + d;
    cout << amnt / 7 + bool(amnt % 7) + 1 << endl;
}