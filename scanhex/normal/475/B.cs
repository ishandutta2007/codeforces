using System;
using System.Diagnostics;
using System.IO;
using System.Text;

namespace Bayan
{
    public class B
    {
        private TextReader Cin = Console.In;
        TextWriter Cout = Console.Out;
        readonly int[] _bad = { ' ', '\r', '\n' };

        private string NextToken()
        {
            var sb = new StringBuilder();
            int i;

            while (Array.IndexOf(_bad, (i = Cin.Read())) != -1 && i != -1) ;
            sb.Append((char)i);

            if (i == -1)
                return null;
            while (Array.IndexOf(_bad, (i = Cin.Read())) == -1 && i != -1)
            {
                sb.Append((char)i);
            }
            return sb.ToString();
        }

        int NextInt()
        {
            return int.Parse(NextToken());
        }

        void Run()
        {
            int n = NextInt(), m = NextInt();
            var hor_left = new bool[n];
            var vert_up = new bool[m];
            var s = NextToken();
            for (var i = 0; i < n; ++i)
            {
                hor_left[i] = s[i] == '<';
            }
            s = NextToken();
            for (var i = 0; i < m; ++i)
            {
                vert_up[i] = s[i] == '^';
            }
            var adjMatrix = new bool[n, m, n, m];
            for (var i = 0; i < n; ++i)
            {
                for (var j = 0; j < m; ++j)
                {
                    for (var k = 0; k < m; ++k)
                    {
                        if (hor_left[i] && j < k)
                            adjMatrix[i, k, i, j] = true;
                        if (!hor_left[i] && j < k)
                            adjMatrix[i, j, i, k] = true;
                    }
                }
            } 
            for (var i = 0; i < m; ++i)
            {
                for (var j = 0; j < n; ++j)
                {
                    for (var k = 0; k < n; ++k)
                    {
                        if (vert_up[i] && j < k)
                            adjMatrix[k, i, j, i] = true;
                        if (!vert_up[i] && j < k)
                            adjMatrix[j, i, k, i] = true;
                    }
                }
            }
            for (var kx = 0; kx < n; ++kx)
                for (var ky = 0; ky < m; ++ky)
                    for (var ix = 0; ix < n; ++ix)
                        for (var iy = 0; iy < m; ++iy)
                            for (var jx = 0; jx < n; ++jx)
                                for (var jy = 0; jy < m; ++jy)
                                    if (adjMatrix[ix, iy, kx, ky] && adjMatrix[kx, ky, jx, jy])
                                        adjMatrix[ix, iy, jx, jy] = true;
            for (var ix = 0; ix < n; ++ix)
                for (var iy = 0; iy < m; ++iy)
                    for (var jx = 0; jx < n; ++jx)
                        for (var jy = 0; jy < m; ++jy)
                            if (!adjMatrix[ix, iy, jx, jy])
                            {
                                Cout.Write("NO");
                                return;
                            }
            Cout.Write("YES");
        }

        void Solve()
        {
            Run();
            Cin.ReadLine();
            Cin.ReadLine();
        }   
        public static void Main(string[] args)
        {
            new B().Solve();
        }
    }
}