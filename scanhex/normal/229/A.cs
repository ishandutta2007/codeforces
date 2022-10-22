using System;
using System.IO;
using System.Text;
using System.Linq;
using System.Collections.Generic;

namespace CF
{
    class A229
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

            int n = NextInt(), m = NextInt();
            int[,] a = new int[n, m];
            for (int i = 0; i < n; ++i)
            {
                var s = NextToken();
                for (int j = 0; j < m; ++j)
                    a[i, j] = s[j] - '0';
            }
            bool flag = true;
            for (int i = 0; i < n; ++i)
                if (Enumerable.Range(0, m).Select(x => a[i, x]).Sum() == 0)
                    flag = false;
            if (!flag)
            {
                sw.Write(-1);
                return;
            }
            int max = int.MaxValue;
            var arr = new List<int>[n];
            for (int i = 0; i < n; ++i)
                arr[i] = Enumerable.Range(0, m).Where(x => a[i, x] == 1).ToList();
            for (int col = 0; col < m; ++col)
            {
                int sum = 0;
                for (int i = 0; i < n; ++i)
                {
                    int min;
                    int ind = arr[i].BinarySearch(col);
                    if (ind >= 0)
                        min = 0;
                    else
                    {
                        min = Math.Min(~ind < arr[i].Count ? arr[i][~ind] - col : int.MaxValue, 
                            ~ind == 0 ? int.MaxValue : col - arr[i][~ind - 1]);
                        min = Math.Min(min, col + m - arr[i][arr[i].Count - 1]);
                        min = Math.Min(min, arr[i][0] + m - col);
                    }
                    sum += min;
                }
                max = Math.Min(sum, max);
            }
            sw.Write(max);
        }

        static void Main(string[] args)
        {
            new A229().run();
        }
    }
}