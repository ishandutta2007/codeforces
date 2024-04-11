using System;
using System.IO;
using System.Text;

namespace CF
{
    class B126
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

        int[] PrefixFunction(string s)
        {
            int[] p = new int[s.Length];
            int j = 0;
            for (int i = 1; i < s.Length; ++i)
            {
                while (s[j] != s[i] && j != 0)
                    j = p[j - 1];
                if (s[i] == s[j])
                    ++j;
                p[i] = j;
            }
            return p;
        }

        void run()
        {
            string s = NextToken();
            var p = PrefixFunction(s);
            var here = new bool[1000000];
            for (int i = 0; i < p.Length - 1; ++i)
                here[p[i]] = true;
            
            for (int i = p[p.Length - 1]; i > 0; i = p[i - 1])
            {
                if (here[i])
                {
                    sw.Write(s.Substring(0, i));
                    return;
                }
            }
            sw.Write("Just a legend");
        }

        static void Main(string[] args)
        {
            new B126().run();
        }
    }
}