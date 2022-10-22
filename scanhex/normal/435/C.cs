using System;
using System.IO;
using System.Text;

namespace CFShuffleSharp
{
    public class C
    {
        private TextReader Cin;
        TextWriter Cout;
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

        void Solve()
        {
            var n = NextInt();
            var a = new int[n];
            var s = 0;
            for (var i = 0; i < n; ++i)
                s += (a[i] = NextInt());
            var matr = new int[s + 1, s << 1 + 1];
            var y = 0;
            var x = 0;
            for (var i = 0; i < n; ++i)
            {
                int y1;
                if (i%2 == 0)
                {
                    for (y1 = y; y1 < y + a[i]; ++y1, ++x)
                    {
                        matr[x, y1 + s] = 1;
                    }
                    --y1;
                }
                else
                {
                    for (y1 = y; y1 > y - a[i]; --y1, ++x)
                    {
                        matr[x, y1 + s] = -1;
                    }
                    ++y1;
                }
                y = y1;
            }
            var max = -1;
            var min = -1;
            for (var j = 2*s - 1; j >= 0; --j)
            {
                for (var i = 0; i <= s; ++i)
                    if (matr[i, j] != 0)
                    {
                        max = j;
                        goto Nex;
                    }
            }
            Nex:
            for (var j = 0; j < 2*s; ++j)
            {
                for (var i = 0; i <= s; ++i)
                    if (matr[i, j] != 0)
                    {
                        min = j;
                        goto Nex1;
                    }
            }
            Nex1:
            for (var j = max; j >= min; --j) 
            {
                StringBuilder sb = new StringBuilder();
                for (var i = 0; i < s; ++i)
                    sb.Append(matr[i, j] == 0 ? ' ' : matr[i, j] == 1 ? '/' : '\\');
                Console.WriteLine(sb);
            }
        }

        void Run()
        {
            Cin = Console.In;
            Cout = Console.Out;
            Solve();
            Cout.Close();
        }

        public static void Main(string[] args)
        {
            new C().Run();
        }
    }
}