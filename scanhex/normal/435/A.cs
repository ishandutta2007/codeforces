using System;
using System.IO;
using System.Text;

namespace CFShuffleSharp
{
    public class A
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
            var m = NextInt();
            var s = 0;
            var sf = 0;
            for (var i = 0; i < n; ++i)
            {
                var x = NextInt();
                if (x <= sf)
                {
                    sf -= x;
                }
                else
                {
                    sf = m - x;
                    s += 1;
                }
            }
            Cout.Write(s);
        }
        

        void Run()
        {
            Cin = Console.In;
            Cout = Console.Out;
            Solve();
            Cout.Close();
            Cin.ReadLine();
            Cin.ReadLine();
        }

        public static void Main(string[] args)
        {
            new A().Run();
        }
    }
}