using System;
using System.IO;
using System.Text;

namespace CF
{
    class D448
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
            long n = NextInt(), m = NextInt();
            long k = long.Parse(NextToken());
            long L = 0, R = n * m;
            while (R - L > 1)
            {
                var M = (R + L) / 2;
                var sum = 0L;
                for (int i = 1; i <= n; ++i)
                    sum += Math.Min(M / i, m);
                if (sum >= k)
                        R = M;
                    else
                        L = M;
            }
            sw.Write(R);
        }

        static void Main(string[] args)
        {
            new D448().run();
        }
    }
}