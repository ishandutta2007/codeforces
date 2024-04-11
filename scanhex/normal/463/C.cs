using System;
using System.IO;
using System.Text;

namespace CF264
{
    class C
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
            int n = NextInt();
            int[,] a = new int[n, n];
            long[] sumdiag1 = new long[(n << 1) - 1];
            long[] sumdiag2 = new long[(n << 1) - 1];
            for (var i = 0; i < n; ++i)
                for (var j = 0; j < n; ++j)
                {
                    a[i, j] = NextInt();
                    sumdiag1[i + j] += a[i, j];
                    sumdiag2[i + n - j - 1] += a[i, j];
                }
            var max1 = -1L;
            var max2 = -1L;
            var maxx1 = -1;
            var maxy1 = -1;
            var maxx2 = -1;
            var maxy2 = -1;
            for (var i = 0; i < n; ++i)
                for (var j = 0; j < n; ++j)
                {
                    var sum = sumdiag1[i + j] + sumdiag2[i + n - j - 1] - a[i, j];
                    if ((i + j) % 2 == 0)
                        if (sum > max1)
                        {
                            max1 = sum;
                            maxx1 = i;
                            maxy1 = j;
                        }
                    if ((i + j) % 2 == 1)
                        if (sum > max2)
                        {
                            max2 = sum;
                            maxx2 = i;
                            maxy2 = j;
                        }
                }
            sw.WriteLine(max1 + max2);
            ++maxx1;
            ++maxy1;
            ++maxx2;
            ++maxy2;
            sw.WriteLine(maxx1 + " " + maxy1 + " " + maxx2 + " " + maxy2);
            sr.ReadLine();
        }

        static void Main(string[] args)
        {
            new C().run();
        }
    }
}