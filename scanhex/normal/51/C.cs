using System;
using System.Globalization;
using System.IO;
using System.Text;

namespace CF
{
    class C51
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
            var x = new int[n];
            for (int i = 0; i < n; ++i)
                x[i] = NextInt();
            Array.Sort(x);
            int L = -1, R = (int)1e9;
            while (R - L > 1)
            {
                var M = (R + L) / 2;
                var x1 = x[0] + M;
                var x2 = x[x.Length - 1] - M;
                int ind1 = Array.BinarySearch(x, x1);
                int ind2 = Array.BinarySearch(x, x2);
                int xx1 = (int)1e9, xx2 = 0;
                if (ind1 < 0 && ~ind1 < n)
                    xx1 = x[~ind1];
                else if (ind1 >= 0 && ind1 < n - 2)
                {
                    while (ind1 < n - 2 && x[ind1 + 1] == x[ind1])
                        ++ind1;
                    xx1 = x[++ind1];
                }
                if (ind2 < 0 && ~ind2 > 0)
                    xx2 = x[~ind2 - 1];
                else if (ind2 > 1)
                {
                    while (ind2 > 1 && x[ind2 - 1] == x[ind2])
                        --ind2;
                    xx2 = x[--ind2];
                }
                if (xx2 - xx1 > M)
                    L = M;
                else
                    R = M;
            }
            var y1 = x[0] + R;
            var y2 = x[x.Length - 1] - R;
            int ind3 = Array.BinarySearch(x, y1);
            int ind4 = Array.BinarySearch(x, y2);
            int yy1 = (int)1e9, yy2 = 0;
            if (ind3 < 0 && ~ind3 < n)
                yy1 = x[~ind3];
            else if (ind3 >= 0 && ind3 < n - 2)
            {
                while (ind3 < n - 2 && x[ind3 + 1] == x[ind3])
                    ++ind3;
                yy1 = x[++ind3];
            }
            if (ind4 < 0 && ~ind4 > 0)
                yy2 = x[~ind4 - 1];
            else if (ind4 > 1)
            {
                while (ind4 > 1 && x[ind4 - 1] == x[ind4])
                    --ind4;
                yy2 = x[--ind4];
            }
            sw.WriteLine((R / 2d).ToString(CultureInfo.InvariantCulture));
            sw.Write((x[0] + R / 2d).ToString(CultureInfo.InvariantCulture) + " " + (x[n - 1] - R / 2d).ToString(CultureInfo.InvariantCulture) + " " + ((yy2 + yy1) / 2d).ToString(CultureInfo.InvariantCulture));
            sr.ReadLine();
            sr.ReadLine();
        }

        static void Main(string[] args)
        {
            new C51().run();
        }
    }
}