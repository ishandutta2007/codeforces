using System;
using System.IO;
using System.Linq;
using System.Text;

namespace ITMO_DP_Contest
{
    class C366
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
            var k = NextInt();
            var a = Enumerable.Range(0, n).Select(x => NextInt()).ToList();
            var b = Enumerable.Range(0, n).Select(x => NextInt()).ToList();
            var MaxSum = (n * 900 << 1) + 1;
            var d = new int[n + 1, MaxSum];
            var reach = new bool[n + 1, MaxSum];
            reach[0, MaxSum / 2] = true;
            for (var i = 0; i < n; ++i)
                for (var j = 0; j < MaxSum; ++j)
                {
                    if (!reach[i, j])
                        continue;
                    d[i + 1, j + a[i] - k * b[i]] = 
                        Math.Max(d[i + 1, j + a[i] - k * b[i]], d[i, j] + a[i]);
                    d[i + 1, j] = Math.Max(d[i + 1, j], d[i, j]);
                    reach[i + 1, j + a[i] - k * b[i]] = true;
                    reach[i + 1, j] = true;
                }
            Console.Write(d[n, MaxSum / 2] != 0 ? d[n, MaxSum / 2] : -1);
        }

        static void Main(string[] args)
        {
            new C366().run();
        }
    }
}