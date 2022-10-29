using System;
using System.Text.RegularExpressions;

namespace arrayvelse
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine(n%2 == 0 && n!= 2 ? "YES" : "NO");
        }
    }
}