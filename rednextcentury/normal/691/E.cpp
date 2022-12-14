#include<bits/stdc++.h>
using namespace std;
const long long  MOD = 1e9 + 7;

struct Matrix
{
    vector< vector<long long > > mat; // the contents of matrix as a 2D-vector
    long long  n_rows, n_cols; // number of rows and columns

    Matrix(vector< vector<long long > > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    static Matrix identity_matrix(long long  n)
    {
        // Return I_n - the identity matrix of size n.
        // This function is static, because it creates a new Matrix instance
        vector< vector<long long > > values(n, vector<long long >(n, 0));
        for(long long  i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const
    {
        long long  n = n_rows, m = other.n_cols;
        vector< vector<long long > > result(n_rows, vector<long long >(m, 0));
        for(long long  i = 0; i < n; i++)
            for(long long  j = 0; j < m; j++) {
                for(long long  k = 0; k < n_cols; k++) {
                    result[i][j] = (result[i][j] + (mat[i][k] * 1ll * other.mat[k][j])%MOD) % MOD;
                }
            }
        // Multiply matrices as usual, then return the result as the new Matrix
        return Matrix(result);
    }

    inline bool is_square() const
    {
        return n_rows == n_cols;
    }
};

Matrix fast_exponentiation(Matrix m, long long power)
{
    assert(m.is_square());
    Matrix result = Matrix::identity_matrix(m.n_rows);

    while(power) {
        if(power & 1)
            result = result * m;
        m = m * m;
        power >>= 1;
    }

    return result;
}
long long a[1000000];
int  main()
{
    long long  n;
    long long k;
    cin>>n>>k;
    for (long long  i=0;i<n;i++)
        cin>>a[i];
    vector<vector<long long > > mat(n,vector<long long >(n));
    for (long long  i=0;i<n;i++)
        for (long long  j=0;j<n;j++)
            if (__builtin_popcountll(a[i]^a[j])%3==0)
                mat[i][j]=1;
            else mat[i][j]=0;
    Matrix x(mat);
    long long ret=0;
    x = fast_exponentiation(x,k-1);
    for (auto y:x.mat)
        for (auto z:y)
            ret=(ret+z)%MOD;
    cout<<ret<<endl;
}