using System;
using System.IO;
using System.Text;

namespace CF455
{
    class A
    {
        readonly int[] _bad = { ' ', '\r', '\n', -1 };
        TextReader sr = Console.In;
        TextWriter sw = Console.Out;

        private string NextToken()
        {
            var sb = new StringBuilder();
            int i;

            while (Array.IndexOf(_bad, (i = sr.Read())) != -1) ;
            sb.Append((char)i);
            while (Array.IndexOf(_bad, (i = sr.Read())) == -1)
                sb.Append((char)i);
            return sb.ToString();
        }

        int NextInt()
        {
            return int.Parse(NextToken());
        }

        void run()
        {
            var n = NextInt();
            var a = new long[(int)1e5 + 1];
            var m = a.Length;
            for (var i = 0; i < n; ++i)
                ++a[NextInt()];
            for (var i = 0; i < m; ++i)
                a[i] *= i;
            var d = new long[m, 2];
            d[1, 0] = d[1, 1] = a[1];
            d[2, 0] = a[2];
            d[2, 1] = Math.Max(d[2, 0], d[1, 1]);
            for (var i = 3; i < m; ++i)
            {
                d[i, 0] = d[i - 2, 1] + a[i];
                d[i, 1] = Math.Max(d[i, 0], d[i - 1, 1]);
            }
            sw.Write(d[m - 1, 1]);
        }

        static void Main(string[] args)
        {
            new A().run();
        }
    }
}